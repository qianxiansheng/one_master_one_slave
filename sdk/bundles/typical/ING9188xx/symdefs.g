att_dispatch_client_can_send_now = 0x00005875;
att_dispatch_client_request_can_send_now_event = 0x0000587b;
att_dispatch_register_client = 0x00005881;
att_dispatch_register_server = 0x00005895;
att_dispatch_server_can_send_now = 0x000058a9;
att_dispatch_server_request_can_send_now_event = 0x000058af;
att_emit_general_event = 0x00005961;
att_server_can_send_packet_now = 0x00006091;
att_server_deferred_read_response = 0x00006095;
att_server_get_mtu = 0x000060ad;
att_server_indicate = 0x00006125;
att_server_init = 0x000061a9;
att_server_notify = 0x000061e5;
att_server_register_packet_handler = 0x000062fd;
att_server_request_can_send_now_event = 0x00006309;
att_set_db = 0x00006325;
att_set_read_callback = 0x00006339;
att_set_write_callback = 0x00006345;
bd_addr_cmp = 0x000064b5;
bd_addr_copy = 0x000064bb;
bd_addr_to_str = 0x000064c5;
big_endian_read_16 = 0x000064fd;
big_endian_read_32 = 0x00006505;
big_endian_store_16 = 0x00006519;
big_endian_store_32 = 0x00006525;
btstack_config = 0x00006679;
btstack_memory_pool_create = 0x000067b7;
btstack_memory_pool_free = 0x000067e1;
btstack_memory_pool_get = 0x00006841;
btstack_push_user_msg = 0x000068a9;
btstack_push_user_runnable = 0x000068b5;
btstack_reset = 0x000068c1;
char_for_nibble = 0x00006b9d;
eTaskConfirmSleepModeStatus = 0x00006e81;
gap_add_dev_to_periodic_list = 0x000074ed;
gap_add_whitelist = 0x000074fd;
gap_aes_encrypt = 0x00007509;
gap_clear_white_lists = 0x00007541;
gap_clr_adv_set = 0x0000754d;
gap_clr_periodic_adv_list = 0x00007559;
gap_create_connection_cancel = 0x00007565;
gap_default_periodic_adv_sync_transfer_param = 0x00007571;
gap_disconnect = 0x00007589;
gap_disconnect_all = 0x000075b5;
gap_ext_create_connection = 0x000075f5;
gap_get_connection_parameter_range = 0x000076cd;
gap_le_read_channel_map = 0x00007709;
gap_periodic_adv_create_sync = 0x00007775;
gap_periodic_adv_create_sync_cancel = 0x00007799;
gap_periodic_adv_set_info_transfer = 0x000077a5;
gap_periodic_adv_sync_transfer = 0x000077b5;
gap_periodic_adv_sync_transfer_param = 0x000077c5;
gap_periodic_adv_term_sync = 0x000077e1;
gap_read_antenna_info = 0x00007869;
gap_read_periodic_adv_list_size = 0x00007875;
gap_read_phy = 0x00007881;
gap_read_remote_used_features = 0x0000788d;
gap_read_remote_version = 0x00007899;
gap_read_rssi = 0x000078a5;
gap_remove_whitelist = 0x000078b1;
gap_rmv_adv_set = 0x0000792d;
gap_rmv_dev_from_periodic_list = 0x00007939;
gap_rx_test_v2 = 0x00007949;
gap_rx_test_v3 = 0x00007959;
gap_set_adv_set_random_addr = 0x000079a5;
gap_set_callback_for_next_hci = 0x000079e1;
gap_set_connection_cte_request_enable = 0x00007a01;
gap_set_connection_cte_response_enable = 0x00007a1d;
gap_set_connection_cte_rx_param = 0x00007a2d;
gap_set_connection_cte_tx_param = 0x00007a81;
gap_set_connection_parameter_range = 0x00007acd;
gap_set_connectionless_cte_tx_enable = 0x00007ae5;
gap_set_connectionless_cte_tx_param = 0x00007af5;
gap_set_connectionless_iq_sampling_enable = 0x00007b51;
gap_set_data_length = 0x00007bad;
gap_set_def_phy = 0x00007bc5;
gap_set_ext_adv_data = 0x00007bd5;
gap_set_ext_adv_enable = 0x00007bed;
gap_set_ext_adv_para = 0x00007c5d;
gap_set_ext_scan_enable = 0x00007d35;
gap_set_ext_scan_para = 0x00007d4d;
gap_set_ext_scan_response_data = 0x00007ded;
gap_set_host_channel_classification = 0x00007e05;
gap_set_periodic_adv_data = 0x00007e15;
gap_set_periodic_adv_enable = 0x00007e85;
gap_set_periodic_adv_para = 0x00007e95;
gap_set_periodic_adv_rx_enable = 0x00007ead;
gap_set_phy = 0x00007ebd;
gap_set_random_device_address = 0x00007ed9;
gap_start_ccm = 0x00007f09;
gap_test_end = 0x00007f51;
gap_tx_test_v2 = 0x00007f5d;
gap_tx_test_v4 = 0x00007f75;
gap_update_connection_parameters = 0x00007f99;
gap_vendor_tx_continuous_wave = 0x00007fdd;
gatt_client_cancel_write = 0x00008505;
gatt_client_discover_characteristic_descriptors = 0x0000852b;
gatt_client_discover_characteristics_for_handle_range_by_uuid128 = 0x0000856b;
gatt_client_discover_characteristics_for_handle_range_by_uuid16 = 0x000085bb;
gatt_client_discover_characteristics_for_service = 0x0000860b;
gatt_client_discover_primary_services = 0x00008641;
gatt_client_discover_primary_services_by_uuid128 = 0x00008673;
gatt_client_discover_primary_services_by_uuid16 = 0x000086b7;
gatt_client_execute_write = 0x000086f3;
gatt_client_find_included_services_for_service = 0x00008719;
gatt_client_get_mtu = 0x00008747;
gatt_client_is_ready = 0x000087e9;
gatt_client_listen_for_characteristic_value_updates = 0x000087ff;
gatt_client_prepare_write = 0x00008821;
gatt_client_read_characteristic_descriptor_using_descriptor_handle = 0x0000885d;
gatt_client_read_long_characteristic_descriptor_using_descriptor_handle = 0x00008887;
gatt_client_read_long_characteristic_descriptor_using_descriptor_handle_with_offset = 0x0000888d;
gatt_client_read_long_value_of_characteristic_using_value_handle = 0x000088bb;
gatt_client_read_long_value_of_characteristic_using_value_handle_with_offset = 0x000088c1;
gatt_client_read_multiple_characteristic_values = 0x000088ef;
gatt_client_read_value_of_characteristic_using_value_handle = 0x0000891f;
gatt_client_read_value_of_characteristics_by_uuid128 = 0x0000894d;
gatt_client_read_value_of_characteristics_by_uuid16 = 0x00008999;
gatt_client_register_handler = 0x000089e5;
gatt_client_reliable_write_long_value_of_characteristic = 0x000089f1;
gatt_client_signed_write_without_response = 0x00008e21;
gatt_client_write_characteristic_descriptor_using_descriptor_handle = 0x00008ee5;
gatt_client_write_client_characteristic_configuration = 0x00008f1f;
gatt_client_write_long_characteristic_descriptor_using_descriptor_handle = 0x00008f71;
gatt_client_write_long_characteristic_descriptor_using_descriptor_handle_with_offset = 0x00008f81;
gatt_client_write_long_value_of_characteristic = 0x00008fbd;
gatt_client_write_long_value_of_characteristic_with_offset = 0x00008fcd;
gatt_client_write_value_of_characteristic = 0x00009009;
gatt_client_write_value_of_characteristic_without_response = 0x0000903f;
hci_add_event_handler = 0x0000a581;
hci_power_control = 0x0000ad1d;
hci_register_acl_packet_handler = 0x0000aed1;
kv_commit = 0x0000b645;
kv_get = 0x0000b6a1;
kv_init = 0x0000b6ad;
kv_init_backend = 0x0000b72d;
kv_put = 0x0000b741;
kv_remove = 0x0000b74d;
kv_remove_all = 0x0000b781;
kv_value_modified = 0x0000b7b1;
kv_value_modified_of_key = 0x0000b7cd;
kv_visit = 0x0000b7d9;
l2cap_add_event_handler = 0x0000b869;
l2cap_can_send_packet_now = 0x0000b879;
l2cap_create_le_credit_based_connection_request = 0x0000ba35;
l2cap_credit_based_send = 0x0000bb79;
l2cap_credit_based_send_continue = 0x0000bba5;
l2cap_disconnect = 0x0000bc21;
l2cap_get_le_credit_based_connection_credits = 0x0000be71;
l2cap_get_peer_mtu_for_local_cid = 0x0000be8d;
l2cap_init = 0x0000c261;
l2cap_le_send_flow_control_credit = 0x0000c357;
l2cap_max_le_mtu = 0x0000c661;
l2cap_register_packet_handler = 0x0000c789;
l2cap_register_service = 0x0000c795;
l2cap_request_can_send_now_event = 0x0000c8a5;
l2cap_request_connection_parameter_update = 0x0000c8bf;
l2cap_send_echo_request = 0x0000cd99;
l2cap_unregister_service = 0x0000ce59;
le_device_db_add = 0x0000ceb1;
le_device_db_find = 0x0000cf89;
le_device_db_from_key = 0x0000cfb5;
le_device_db_iter_cur = 0x0000cfbd;
le_device_db_iter_cur_key = 0x0000cfc1;
le_device_db_iter_init = 0x0000cfc5;
le_device_db_iter_next = 0x0000cfcd;
le_device_db_remove_key = 0x0000cff3;
ll_aes_encrypt = 0x0000d021;
ll_config = 0x0000d09d;
ll_free = 0x0000d0d3;
ll_get_heap_free_size = 0x0000d0dd;
ll_hint_on_ce_len = 0x0000d0f1;
ll_legacy_adv_set_interval = 0x0000d129;
ll_malloc = 0x0000d139;
ll_query_timing_info = 0x0000d271;
ll_register_hci_acl_previewer = 0x0000d2bd;
ll_scan_set_fixed_channel = 0x0000d321;
ll_set_adv_access_address = 0x0000d539;
ll_set_adv_coded_scheme = 0x0000d545;
ll_set_conn_acl_report_latency = 0x0000d575;
ll_set_conn_coded_scheme = 0x0000d5a5;
ll_set_conn_latency = 0x0000d5d1;
ll_set_conn_tx_power = 0x0000d601;
ll_set_def_antenna = 0x0000d649;
ll_set_initiating_coded_scheme = 0x0000d665;
ll_set_max_conn_number = 0x0000d671;
nibble_for_char = 0x0001e6f9;
platform_32k_rc_auto_tune = 0x0001e7a5;
platform_32k_rc_tune = 0x0001e821;
platform_calibrate_32k = 0x0001e835;
platform_config = 0x0001e839;
platform_delete_timer = 0x0001e95d;
platform_enable_irq = 0x0001e965;
platform_get_current_task = 0x0001e99d;
platform_get_gen_os_driver = 0x0001e9c1;
platform_get_heap_status = 0x0001e9c9;
platform_get_link_layer_interf = 0x0001e9e1;
platform_get_task_handle = 0x0001e9e9;
platform_get_timer_counter = 0x0001ea09;
platform_get_us_time = 0x0001ea0d;
platform_get_version = 0x0001ea11;
platform_hrng = 0x0001ea19;
platform_install_isr_stack = 0x0001ea21;
platform_install_task_stack = 0x0001ea2d;
platform_patch_rf_init_data = 0x0001ea65;
platform_printf = 0x0001ea71;
platform_raise_assertion = 0x0001ea85;
platform_rand = 0x0001ea99;
platform_read_info = 0x0001ea9d;
platform_read_persistent_reg = 0x0001eacd;
platform_reset = 0x0001eadd;
platform_set_abs_timer = 0x0001eb01;
platform_set_evt_callback = 0x0001eb05;
platform_set_evt_callback_table = 0x0001eb19;
platform_set_irq_callback = 0x0001eb25;
platform_set_irq_callback_table = 0x0001eb41;
platform_set_rf_clk_source = 0x0001eb4d;
platform_set_rf_init_data = 0x0001eb59;
platform_set_rf_power_mapping = 0x0001eb65;
platform_set_timer = 0x0001eb71;
platform_shutdown = 0x0001eb75;
platform_switch_app = 0x0001eb79;
platform_trace_raw = 0x0001eba5;
platform_write_persistent_reg = 0x0001ebbd;
printf_hexdump = 0x0001ed71;
pvPortMalloc = 0x0001f865;
pvTaskIncrementMutexHeldCount = 0x0001f94d;
pvTimerGetTimerID = 0x0001f965;
pxPortInitialiseStack = 0x0001f991;
reverse_128 = 0x0001fb71;
reverse_24 = 0x0001fb77;
reverse_256 = 0x0001fb7d;
reverse_48 = 0x0001fb83;
reverse_56 = 0x0001fb89;
reverse_64 = 0x0001fb8f;
reverse_bd_addr = 0x0001fb95;
reverse_bytes = 0x0001fb9b;
sm_add_event_handler = 0x0001fe89;
sm_address_resolution_lookup = 0x0001ffe1;
sm_authenticated = 0x0002035d;
sm_authorization_decline = 0x0002036b;
sm_authorization_grant = 0x0002038b;
sm_authorization_state = 0x000203ab;
sm_bonding_decline = 0x000203c5;
sm_config = 0x00020821;
sm_config_conn = 0x00020839;
sm_encryption_key_size = 0x000209ef;
sm_just_works_confirm = 0x00020f75;
sm_le_device_key = 0x000212c1;
sm_passkey_input = 0x00021357;
sm_private_random_address_generation_get = 0x00021711;
sm_private_random_address_generation_get_mode = 0x00021719;
sm_private_random_address_generation_set_mode = 0x00021725;
sm_private_random_address_generation_set_update_period = 0x0002174d;
sm_register_external_ltk_callback = 0x00021889;
sm_register_oob_data_callback = 0x00021895;
sm_request_pairing = 0x000218a1;
sm_send_security_request = 0x00022377;
sm_set_accepted_stk_generation_methods = 0x0002239d;
sm_set_authentication_requirements = 0x000223a9;
sm_set_encryption_key_size_range = 0x000223b5;
sscanf_bd_addr = 0x00022711;
sysSetPublicDeviceAddr = 0x00022ac5;
uuid128_to_str = 0x0002324d;
uuid_add_bluetooth_prefix = 0x000232a5;
uuid_has_bluetooth_prefix = 0x000232c5;
uxListRemove = 0x000232e1;
uxQueueMessagesWaiting = 0x00023309;
uxQueueMessagesWaitingFromISR = 0x00023331;
uxQueueSpacesAvailable = 0x0002334d;
uxTaskGetStackHighWaterMark = 0x00023379;
uxTaskPriorityGet = 0x00023399;
uxTaskPriorityGetFromISR = 0x000233b5;
vListInitialise = 0x0002346f;
vListInitialiseItem = 0x00023485;
vListInsert = 0x0002348b;
vListInsertEnd = 0x000234bb;
vPortEndScheduler = 0x000234d5;
vPortEnterCritical = 0x00023501;
vPortExitCritical = 0x00023545;
vPortFree = 0x00023579;
vPortSuppressTicksAndSleep = 0x0002360d;
vPortValidateInterruptPriority = 0x00023735;
vQueueDelete = 0x00023791;
vQueueWaitForMessageRestricted = 0x000237bd;
vTaskDelay = 0x00023805;
vTaskInternalSetTimeOutState = 0x00023851;
vTaskMissedYield = 0x00023861;
vTaskPlaceOnEventList = 0x0002386d;
vTaskPlaceOnEventListRestricted = 0x000238a5;
vTaskPriorityDisinheritAfterTimeout = 0x000238e5;
vTaskPrioritySet = 0x00023991;
vTaskResume = 0x00023a59;
vTaskStartScheduler = 0x00023add;
vTaskStepTick = 0x00023b6d;
vTaskSuspend = 0x00023b9d;
vTaskSuspendAll = 0x00023c59;
vTaskSwitchContext = 0x00023c69;
xPortStartScheduler = 0x00023d11;
xQueueAddToSet = 0x00023dd9;
xQueueCreateCountingSemaphore = 0x00023dfd;
xQueueCreateCountingSemaphoreStatic = 0x00023e39;
xQueueCreateMutex = 0x00023e7d;
xQueueCreateMutexStatic = 0x00023e93;
xQueueCreateSet = 0x00023ead;
xQueueGenericCreate = 0x00023eb5;
xQueueGenericCreateStatic = 0x00023f01;
xQueueGenericReset = 0x00023f69;
xQueueGenericSend = 0x00023ff5;
xQueueGenericSendFromISR = 0x00024161;
xQueueGiveFromISR = 0x00024221;
xQueueGiveMutexRecursive = 0x000242c5;
xQueueIsQueueEmptyFromISR = 0x00024305;
xQueueIsQueueFullFromISR = 0x00024329;
xQueuePeek = 0x00024351;
xQueuePeekFromISR = 0x00024479;
xQueueReceive = 0x000244e5;
xQueueReceiveFromISR = 0x00024611;
xQueueRemoveFromSet = 0x000246a5;
xQueueSelectFromSet = 0x000246c7;
xQueueSelectFromSetFromISR = 0x000246d9;
xQueueSemaphoreTake = 0x000246ed;
xQueueTakeMutexRecursive = 0x00024859;
xTaskCheckForTimeOut = 0x0002489d;
xTaskCreate = 0x0002490d;
xTaskCreateStatic = 0x00024969;
xTaskGetCurrentTaskHandle = 0x000249d9;
xTaskGetSchedulerState = 0x000249e5;
xTaskGetTickCount = 0x00024a01;
xTaskGetTickCountFromISR = 0x00024a0d;
xTaskIncrementTick = 0x00024a1d;
xTaskPriorityDisinherit = 0x00024ae9;
xTaskPriorityInherit = 0x00024b7d;
xTaskRemoveFromEventList = 0x00024c11;
xTaskResumeAll = 0x00024c91;
xTaskResumeFromISR = 0x00024d59;
xTimerCreate = 0x00024de5;
xTimerCreateStatic = 0x00024e19;
xTimerCreateTimerTask = 0x00024e51;
xTimerGenericCommand = 0x00024ebd;
xTimerGetExpiryTime = 0x00024f2d;
xTimerGetTimerDaemonTaskHandle = 0x00024f4d;