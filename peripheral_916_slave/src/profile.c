#include <stddef.h>
#include "platform_api.h"
#include "att_db.h"
#include "gap.h"
#include "btstack_event.h"
#include "btstack_defines.h"

#include "FreeRTOS.h"
#include "timers.h"

// GATT characteristic handles
#include "../data/gatt.const"

const static uint8_t adv_data[] = {
    #include "../data/advertising.adv"
};

const static uint8_t scan_data[] = {
    #include "../data/scan_response.adv"
};

const static uint8_t profile_data[] = {
    #include "../data/gatt.profile"
};

static uint32_t total_bytes = 0;
static hci_con_handle_t handle_send = 0;
static uint8_t notify_enable = 0;
uint8_t loopback_mode = 0;

static uint16_t att_read_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t offset, 
                                  uint8_t * buffer, uint16_t buffer_size)
{
    switch (att_handle)
    {
    case HANDLE_GENERIC_INPUT:
        if (buffer != NULL)
        {
            *(uint32_t *)buffer = total_bytes;
            return buffer_size;
        }
        else
            return sizeof(total_bytes);
    default:
        return 0;
    }
}

static btstack_packet_callback_registration_t hci_event_callback_registration;

static int att_write_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t transaction_mode, 
                              uint16_t offset, const uint8_t *buffer, uint16_t buffer_size)
{
    switch (att_handle)
    {
    case HANDLE_GENERIC_INPUT:
        platform_printf("Receive from master:");
        printf_hexdump(buffer, buffer_size);
        return 0;
    case HANDLE_GENERIC_OUTPUT + 1:        
        if(*(uint16_t *)buffer == GATT_CLIENT_CHARACTERISTICS_CONFIGURATION_NOTIFICATION)
        {
            platform_printf("configuration notification!\r\n");
            notify_enable = 1;
        }
        else
            notify_enable = 0;        
        return 0;
    default:
        return 0;
    }
}

static void user_msg_handler(uint32_t msg_id, void *data, uint16_t size)
{
    switch (msg_id)
    {
        // add your code
    //case MY_MESSAGE_ID:
    //    break;
    default:
        ;
    }
}

static void hint_ce_len(uint16_t interval)
{
    uint16_t ce_len = interval << 1;
    if (ce_len > 20)
        ll_hint_on_ce_len(0, ce_len - 15, ce_len - 15);
}

static void user_packet_handler(uint8_t packet_type, uint16_t channel, const uint8_t *packet, uint16_t size)
{
    const static ext_adv_set_en_t adv_sets_en[] = {{.handle = 0, .duration = 0, .max_events = 0}};
    bd_addr_t rand_addr = {0xFB, 0x89, 0x67, 0x45, 0x23, 0x01};    // TODO: random address generation
    uint8_t event = hci_event_packet_get_type(packet);
    const btstack_user_msg_t *p_user_msg;
    if (packet_type != HCI_EVENT_PACKET) return;

    switch (event)
    {
    case BTSTACK_EVENT_STATE:
        if (btstack_event_state_get_state(packet) != HCI_STATE_WORKING)
            break;
        platform_printf("start adv");
        gap_set_adv_set_random_addr(0, rand_addr);

#ifdef LONG_RANGE
        gap_set_ext_adv_para(0, 
                                CONNECTABLE_ADV_BIT,
                                80, 80,            // Primary_Advertising_Interval_Min, Primary_Advertising_Interval_Max
                                PRIMARY_ADV_ALL_CHANNELS,  // Primary_Advertising_Channel_Map
                                BD_ADDR_TYPE_LE_RANDOM,    // Own_Address_Type
                                BD_ADDR_TYPE_LE_PUBLIC,    // Peer_Address_Type (ignore)
                                NULL,                      // Peer_Address      (ignore)
                                ADV_FILTER_ALLOW_ALL,      // Advertising_Filter_Policy
                                127,                       // Advertising_Tx_Power
                                PHY_CODED,                 // Primary_Advertising_PHY
                                0,                         // Secondary_Advertising_Max_Skip
                                PHY_CODED,                 // Secondary_Advertising_PHY
                                0x00,                      // Advertising_SID
                                0x00);                     // Scan_Request_Notification_Enable
#else
        gap_set_ext_adv_para(0, 
                                CONNECTABLE_ADV_BIT | SCANNABLE_ADV_BIT | LEGACY_PDU_BIT,
                                32, 32,            // Primary_Advertising_Interval_Min, Primary_Advertising_Interval_Max
                                PRIMARY_ADV_ALL_CHANNELS,  // Primary_Advertising_Channel_Map
                                BD_ADDR_TYPE_LE_RANDOM,    // Own_Address_Type
                                BD_ADDR_TYPE_LE_PUBLIC,    // Peer_Address_Type (ignore)
                                NULL,                      // Peer_Address      (ignore)
                                ADV_FILTER_ALLOW_ALL,      // Advertising_Filter_Policy
                                0x00,                      // Advertising_Tx_Power
                                PHY_1M,                    // Primary_Advertising_PHY
                                0,                         // Secondary_Advertising_Max_Skip
                                PHY_1M,                    // Secondary_Advertising_PHY
                                0x00,                      // Advertising_SID
                                0x00);                     // Scan_Request_Notification_Enable
#endif
        gap_set_ext_adv_data(0, sizeof(adv_data), (uint8_t*)adv_data);
        gap_set_ext_scan_response_data(0, sizeof(scan_data), (uint8_t*)scan_data);
        gap_set_ext_adv_enable(1, sizeof(adv_sets_en) / sizeof(adv_sets_en[0]), adv_sets_en);
        break;

    case HCI_EVENT_LE_META:
        switch (hci_event_le_meta_get_subevent_code(packet))
        {
        case HCI_SUBEVENT_LE_ENHANCED_CONNECTION_COMPLETE:
            {
                const le_meta_event_enh_create_conn_complete_t *cmpl =
                    decode_hci_le_meta_event(packet, le_meta_event_enh_create_conn_complete_t);
                handle_send = cmpl->handle;
                hint_ce_len(cmpl->interval);
                att_set_db(handle_send, profile_data);
                platform_printf("connected\r\n");
            }
            break;
        case HCI_SUBEVENT_LE_PHY_UPDATE_COMPLETE:
            {
                const le_meta_phy_update_complete_t *cmpl = decode_hci_le_meta_event(packet, le_meta_phy_update_complete_t);
                platform_printf("PHY updated: Rx %d, Tx %d", cmpl->rx_phy, cmpl->tx_phy);
            }
            break;
        case HCI_SUBEVENT_LE_CONNECTION_UPDATE_COMPLETE:
            {
                const le_meta_event_conn_update_complete_t *cmpl = decode_hci_le_meta_event(packet, le_meta_event_conn_update_complete_t);
                platform_printf("CONN updated: interval %.2f ms", cmpl->interval * 1.25);
            }
            break;
        default:
            break;
        }

        break;

    case HCI_EVENT_DISCONNECTION_COMPLETE:
        notify_enable = 0;
        platform_printf("start adv");
        gap_set_ext_adv_enable(1, sizeof(adv_sets_en) / sizeof(adv_sets_en[0]), adv_sets_en);
        break;
    
    case ATT_EVENT_MTU_EXCHANGE_COMPLETE:
        platform_printf("ATT_EVENT_MTU updated: %d\n", att_event_mtu_exchange_complete_get_MTU(packet));
        break;

    case ATT_EVENT_CAN_SEND_NOW:
        break;

    case BTSTACK_EVENT_USER_MSG:
        p_user_msg = hci_event_packet_get_user_msg(packet);
        user_msg_handler(p_user_msg->msg_id, p_user_msg->data, p_user_msg->len);
        break;

    default:
        break;
    }
}


void callback(TimerHandle_t xTimer)
{
    static uint32_t count = 0;
    
    count++;
    
    if (notify_enable)
        att_server_notify(handle_send, HANDLE_GENERIC_OUTPUT, (uint8_t*)&(count), sizeof(count));
}
    
uint32_t setup_profile(void *data, void *user_data)
{   
    
    TimerHandle_t timer = xTimerCreate("timer1", pdMS_TO_TICKS(1000), pdTRUE, NULL, callback);
    xTimerStart(timer, portMAX_DELAY);
    
    att_server_init(att_read_callback, att_write_callback);
    hci_event_callback_registration.callback = &user_packet_handler;
    hci_add_event_handler(&hci_event_callback_registration);
    att_server_register_packet_handler(&user_packet_handler);
    return 0;
}
