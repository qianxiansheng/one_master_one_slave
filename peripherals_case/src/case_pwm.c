/* $(license) */

/* 
 * more detail：
 *     https://ingchips.github.io/drafts/pg_ing916/ch-pinctrl.html
 *     https://ingchips.github.io/drafts/pg_ing916/ch-pwm.html
 *     datasheet
 * 一般需要恢复PinCtrl和PWM的时钟（即消除门控）
 * 
 * 利用PWM_SetupSimple函数配置指定频率和占空比的PWM波形
 * 
 * 利用硬件Timer实现更多路的PWN输出
 *
 * 注意：由于GPIO不是全映射，某些IO口不能用在某些外设接口上，所以需查阅IO映射表，可以从datasheet中查看
 * 例如：ING9182C中：
 *     pwm_0a: 0,2,4,6,8,10,12,14,16,21,31,35  可用
 *     pwm_0b: 1,3,5,7,9,11,13,15,17,22        可用
 */
 
#include "case_pwm.h"

// PWM
#if CASE_PWM
#define CASE_PWM_MAX_OUTPUT             // 利用Timer完成9路独立PWM输出
//#define CASE_PWM_COMPLEMENT_OUTPUT      // 互补输出
//#define CASE_PWM_DIED_ZONE_OUTPUT       // UP_WITH_DIED_ZONE 工作模式
//#define CASE_PWM_ZEROING_ISSUE_TEST

#define PIN_LED1_A GIO_GPIO_4
#define PIN_LED2_A GIO_GPIO_6
#define PIN_LED3_A GIO_GPIO_8
#define PIN_LED4_A GIO_GPIO_10
#define PIN_LED5_B GIO_GPIO_3
#define PIN_LED6_B GIO_GPIO_5
#define PIN_LED7_B GIO_GPIO_7
#define PIN_LED8_B GIO_GPIO_9
#define PIN_LED9_B GIO_GPIO_15

void TMR_PWM_SetupSimple(TMR_TypeDef *pTMR, uint8_t ch_id, uint32_t freq_clk, uint32_t frequency, uint32_t on_duty)
{
    uint32_t pera = freq_clk / frequency;
    uint32_t high = pera > 1000 ? pera / 100 * on_duty : pera * on_duty / 100;
    uint32_t low = pera > 1000 ? pera / 100 * (100 - on_duty) : pera * (100 - on_duty) / 100;
    TMR_SetReload(pTMR, ch_id, (high << 16) | low);
}

void pwm_test_init()
{
    SYSCTRL_ClearClkGateMulti((1 << SYSCTRL_ITEM_APB_SysCtrl)
                            | (1 << SYSCTRL_ITEM_APB_PinCtrl)
                            | (1 << SYSCTRL_ITEM_APB_PWM)
                            | (1 << SYSCTRL_ITEM_APB_TMR0)
                            | (1 << SYSCTRL_ITEM_APB_TMR1)
                            | (1 << SYSCTRL_ITEM_APB_TMR2));
    
#ifdef CASE_PWM_COMPLEMENT_OUTPUT
    PINCTRL_SetPadMux(PIN_LED1_A, IO_SOURCE_PWM0_A);
    PINCTRL_SetPadMux(PIN_LED5_B, IO_SOURCE_PWM0_B);
    PWM_SetupSimple(0, 100, 20);
#endif
    
#ifdef CASE_PWM_DIED_ZONE_OUTPUT
    PINCTRL_SetPadMux(PIN_LED1_A, IO_SOURCE_PWM0_A);
    PINCTRL_SetPadMux(PIN_LED5_B, IO_SOURCE_PWM0_B);
    PWM_SetupSimple(0, 100, 20);
    
    uint32_t frequency = 100;
    
    const uint8_t channel_index = 0;
    
    uint32_t pera = PWM_CLOCK_FREQ / frequency;
    uint32_t high = pera >> 1;
    uint32_t diedzone = pera >> 2;
    PWM_HaltCtrlEnable(channel_index, 1);
    PWM_Enable(channel_index, 0);
    PWM_SetPeraThreshold(channel_index, pera);
#if (INGCHIPS_FAMILY == INGCHIPS_FAMILY_918)
    PWM_SetMultiDutyCycleCtrl(channel_index, 0);        // do not use multi duty cycles
#endif
    PWM_SetHighThreshold(channel_index, 0, high);
    PWM_SetDiedZoneThreshold(channel_index, diedzone);
    PWM_SetMode(channel_index, PWM_WORK_MODE_UP_WITH_DIED_ZONE);
    PWM_SetMask(channel_index, 0, 0);
    PWM_Enable(channel_index, 1);
    PWM_HaltCtrlEnable(channel_index, 0);
#endif

#ifdef CASE_PWM_ZEROING_ISSUE_TEST
    // TODO: 

    //PWM Timer impl
    SYSCTRL_SelectTimerClk(TMR_PORT_1, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR1, 0, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);

    uint32_t freq_clk = 32000;
    const uint8_t ch_id = 0;
    const uint32_t frequency = 1;
    const uint16_t on_duty = 100;

    uint32_t pera = freq_clk / frequency;
    uint32_t high = pera > 1000 ? pera / 100 * on_duty : pera * on_duty / 100;
    uint32_t low = pera > 1000 ? pera / 100 * (100 - on_duty) : pera * (100 - on_duty) / 100;
    TMR_SetReload(APB_TMR1, ch_id, ((high - 1) << 16) | low);
    platform_printf("freq_clk:%d, frequency:%d, pera:%d, high:%d, low:%d\n", freq_clk, frequency, pera, high, low);
    platform_printf("reload:%08X\n", ((high - 1) << 16) | low);
    
    PINCTRL_SetPadMux(PIN_LED4_A, IO_SOURCE_TIMER1_PWM0_A);
    // 0b1000
    TMR_Enable(APB_TMR1, 0, 0xf);
#endif
    
#ifdef CASE_PWM_MAX_OUTPUT
    //配置PWM
    PINCTRL_SetPadMux(PIN_LED1_A, IO_SOURCE_PWM0_A);
    PWM_SetupSimple(0, 16000, 50);    //内部执行了PWM_Enable(channel_index, 1);
    
    PINCTRL_SetPadMux(PIN_LED2_A, IO_SOURCE_PWM1_A);
    PWM_SetupSimple(1, 16000, 20);    //内部执行了PWM_Enable(channel_index, 1);
    
    PINCTRL_SetPadMux(PIN_LED3_A, IO_SOURCE_PWM2_A);
    PWM_SetupSimple(2, 16000, 80);    //内部执行了PWM_Enable(channel_index, 1);


    //PWM Timer impl
    SYSCTRL_SelectTimerClk(TMR_PORT_1, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR1, 0, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);
    TMR_PWM_SetupSimple(APB_TMR1, 0, 32000, 10, 50);
    PINCTRL_SetPadMux(PIN_LED4_A, IO_SOURCE_TIMER1_PWM0_A);
    
    SYSCTRL_SelectTimerClk(TMR_PORT_1, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR1, 1, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);
    TMR_PWM_SetupSimple(APB_TMR1, 1, 32000, 10, 10);
    PINCTRL_SetPadMux(PIN_LED5_B, IO_SOURCE_TIMER1_PWM1_B);
    
    SYSCTRL_SelectTimerClk(TMR_PORT_2, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR2, 0, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);
    TMR_PWM_SetupSimple(APB_TMR2, 0, 32000, 10, 20);
    PINCTRL_SetPadMux(PIN_LED6_B, IO_SOURCE_TIMER2_PWM0_B);
    
    SYSCTRL_SelectTimerClk(TMR_PORT_2, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR2, 1, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);
    TMR_PWM_SetupSimple(APB_TMR2, 1, 32000, 10, 30);
    PINCTRL_SetPadMux(PIN_LED7_B, IO_SOURCE_TIMER2_PWM1_B);
    
    SYSCTRL_SelectTimerClk(TMR_PORT_0, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR0, 0, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);
    TMR_PWM_SetupSimple(APB_TMR0, 0, 32000, 10, 40);
    PINCTRL_SetPadMux(PIN_LED8_B, IO_SOURCE_TIMER0_PWM0_B);
    
    SYSCTRL_SelectTimerClk(TMR_PORT_0, SYSCTRL_CLK_32k);
    TMR_SetOpMode      (APB_TMR0, 1, TMR_CTL_OP_MODE_16BIT_PWM, TMR_CLK_MODE_EXTERNAL, 0);
    TMR_PWM_SetupSimple(APB_TMR0, 1, 32000, 10, 50);
    PINCTRL_SetPadMux(PIN_LED9_B, IO_SOURCE_TIMER0_PWM1_B);
#endif
}
void pwm_test()
{
    vTaskDelay(pdMS_TO_TICKS(3000));
    
#ifdef CASE_PWM_COMPLEMENT_OUTPUT
#endif
    
#ifdef CASE_PWM_MAX_OUTPUT
    TMR_Enable(APB_TMR1, 0, (1 << 3));
    TMR_Enable(APB_TMR1, 1, (1 << 3));
    TMR_Enable(APB_TMR2, 0, (1 << 3));
    TMR_Enable(APB_TMR2, 1, (1 << 3));
    TMR_Enable(APB_TMR0, 0, (1 << 3));
    TMR_Enable(APB_TMR0, 1, (1 << 3));
#endif
}

#endif

