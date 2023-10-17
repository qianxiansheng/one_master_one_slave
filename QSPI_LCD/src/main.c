#include <stdio.h>
#include <string.h>
#include "ingsoc.h"
#include "platform_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "trace.h"
#include "timers.h"

extern void setup_peripherals_spi(void);
void peripherals_spi_send_data(void);

static uint32_t cb_hard_fault(hard_fault_info_t *info, void *_)
{
    platform_printf("HARDFAULT:\nPC : 0x%08X\nLR : 0x%08X\nPSR: 0x%08X\n"
                    "R0 : 0x%08X\nR1 : 0x%08X\nR2 : 0x%08X\nP3 : 0x%08X\n"
                    "R12: 0x%08X\n",
                    info->pc, info->lr, info->psr,
                    info->r0, info->r1, info->r2, info->r3, info->r12);
    for (;;);
}

static uint32_t cb_assertion(assertion_info_t *info, void *_)
{
    platform_printf("[ASSERTION] @ %s:%d\n",
                    info->file_name,
                    info->line_no);
    for (;;);
}

static uint32_t cb_heap_out_of_mem(uint32_t tag, void *_)
{
    platform_printf("[OOM] @ %d\n", tag);
    for (;;);
}

#define PRINT_PORT    APB_UART0

uint32_t cb_putc(char *c, void *dummy)
{
    while (apUART_Check_TXFIFO_FULL(PRINT_PORT) == 1);
    UART_SendData(PRINT_PORT, (uint8_t)*c);
    return 0;
}

int fputc(int ch, FILE *f)
{
    cb_putc((char *)&ch, NULL);
    return ch;
}

void config_uart(uint32_t freq, uint32_t baud)
{
    UART_sStateStruct config;

    config.word_length       = UART_WLEN_8_BITS;
    config.parity            = UART_PARITY_NOT_CHECK;
    config.fifo_enable       = 1;
    config.two_stop_bits     = 0;
    config.receive_en        = 1;
    config.transmit_en       = 1;
    config.UART_en           = 1;
    config.cts_en            = 0;
    config.rts_en            = 0;
    config.rxfifo_waterlevel = 1;
    config.txfifo_waterlevel = 1;
    config.ClockFrequency    = freq;
    config.BaudRate          = baud;

    apUART_Initialize(PRINT_PORT, &config, 0);
}

#define RESET_PIN       23
#define CS_PIN          18

static void setup_peripherals_gpio()
{
    SYSCTRL_ClearClkGateMulti((1 << SYSCTRL_ClkGate_APB_GPIO0)
                             |(1 << SYSCTRL_ClkGate_APB_PinCtrl));
    
    // RESET
    PINCTRL_SetPadMux(RESET_PIN, IO_SOURCE_GPIO);
    PINCTRL_Pull(RESET_PIN, PINCTRL_PULL_UP);
    GIO_SetDirection(RESET_PIN, GIO_DIR_OUTPUT);
    
    // CS
    PINCTRL_SetPadMux(CS_PIN, IO_SOURCE_GPIO);
    PINCTRL_Pull(CS_PIN, PINCTRL_PULL_UP);
    GIO_SetDirection(CS_PIN, GIO_DIR_OUTPUT);
}

void setup_peripherals(void)
{
    config_uart(OSC_CLK_FREQ, 115200);
    
    setup_peripherals_gpio();

    setup_peripherals_spi();
}


extern void lcd_gc9c01_init(void);
extern void am_test_screen(void);
extern void GC9C01_HSD1_28_Init(void);
extern void lcd_gc9c01_read_manufacturer(void);

uint32_t setup_profile(void *data, void *user_data)
{
    platform_printf("setup profile..\n");
    
    lcd_gc9c01_init();
    
    vTaskDelay(pdMS_TO_TICKS(1000));
    
    am_test_screen();
    
    return 0;
}

static const platform_evt_cb_table_t evt_cb_table =
{
    .callbacks = {
        [PLATFORM_CB_EVT_HARD_FAULT] = {
            .f = (f_platform_evt_cb)cb_hard_fault,
        },
        [PLATFORM_CB_EVT_ASSERTION] = {
            .f = (f_platform_evt_cb)cb_assertion,
        },
        [PLATFORM_CB_EVT_HEAP_OOM] = {
            .f = (f_platform_evt_cb)cb_heap_out_of_mem,
        },
        [PLATFORM_CB_EVT_PROFILE_INIT] = {
            .f = setup_profile,
        },
        [PLATFORM_CB_EVT_PUTC] = {
            .f = (f_platform_evt_cb)cb_putc,
        },
    }
};

int app_main()
{
    platform_32k_rc_auto_tune();
    // setup event handlers
    platform_set_evt_callback_table(&evt_cb_table);

    setup_peripherals();
    SYSCTRL_Init();    return 0;
}

