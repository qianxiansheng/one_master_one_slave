#include <stdio.h>
#include <string.h>
#include "ingsoc.h"
#include "platform_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "trace.h"
#include "timers.h"

// ============================ static definition ===============================

//SYSCTRL_CLK_PLL_DIV_4 means 336M / 4 = 84M
//"eSclkDiv == 1"       means 84M/(2*(1+1)) = 21M(spi clk speed)
#define SPI_INTERFACETIMINGSCLKDIV_SPI1_21M    (1)


#define SPI_MIC_CLK         GIO_GPIO_19
#define SPI_MIC_MOSI        GIO_GPIO_28
#define SPI_MIC_MISO        GIO_GPIO_27
#define SPI_MIC_CS          GIO_GPIO_18
#define SPI_MIC_WP          GIO_GPIO_26
#define SPI_MIC_HOLD        GIO_GPIO_20

#define SPI_MASTER_PARAM { SPI_INTERFACETIMINGSCLKDIV_DEFAULT_2M, \
SPI_CPHA_ODD_SCLK_EDGES, SPI_CPOL_SCLK_LOW_IN_IDLE_STATES, \
SPI_LSB_MOST_SIGNIFICANT_BIT_FIRST, SPI_DATALEN_8_BITS, SPI_SLVMODE_MASTER_MODE, \
SPI_TRANSMODE_WRITE_ONLY, SPI_DUALQUAD_QUAD_IO_MODE, 1, 1, \
SPI_ADDREN_ENABLE, SPI_CMDEN_ENABLE, (1 << bsSPI_INTREN_ENDINTEN), \
0, 0, SPI_SLVDATAONLY_DISABLE, SPI_ADDRLEN_3_BYTES }

apSSP_sDeviceControlBlock pParam = SPI_MASTER_PARAM;

#define QUAD_MODE // SINGLE_MODE
// ============================ functions ===============================

#define QSPI_STIG_CMD_WRITE 2

void LCD_QSPI_inteface0(uint8_t cmd, uint8_t *param, uint16_t len)
{
    uint8_t buffer[35];

    uint16_t data_len = 3 + len;
    buffer[0] = 0x00;
    buffer[1] = cmd;
    buffer[2] = 0x00;
    memcpy(&buffer[3], param, len);
    
    pParam.eQuadMode = SPI_DUALQUAD_REGULAR_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_ENABLE;
    pParam.eWriteTransCnt = data_len;
    pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
    
    apSSP_WriteCmd(AHB_SSP0, 0, QSPI_STIG_CMD_WRITE);
    for (uint32_t i = 0; i < data_len; ++i)
    {
        apSSP_WriteFIFO(AHB_SSP0, buffer[i]);
    }
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
}

void rtl_gc9c01_qspi_write_cmd0(const uint8_t cmd)
{
    uint8_t buf[3] = {0x00, cmd, 0x00};
    
    pParam.eQuadMode = SPI_DUALQUAD_REGULAR_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_ENABLE;
    pParam.eWriteTransCnt = 3;
    pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
    
    apSSP_WriteCmd(AHB_SSP0, 0, QSPI_STIG_CMD_WRITE);
    for (uint32_t i = 0; i < 3; ++i)
    {
        apSSP_WriteFIFO(AHB_SSP0, buf[i]);
    }
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
}

void rtl_gc9c01_qspi_write_cmd_quad0(const uint8_t cmd)
{
    uint8_t buf[3] = {0x00, cmd, 0x00};
    
    pParam.eQuadMode = SPI_DUALQUAD_QUAD_IO_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_ENABLE;
    pParam.eWriteTransCnt = 3;
    pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
    
    apSSP_WriteCmd(AHB_SSP0, 0, 0x12);
    for (uint32_t i = 0; i < 3; ++i)
    {
        apSSP_WriteFIFO(AHB_SSP0, buf[i]);
    }
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
}

void rtl_gc9c01_qspi_cmd_param0(uint8_t cmd, uint8_t param)
{
    uint8_t buf[4] = {0x00, cmd, 0x00, param};
    
    pParam.eQuadMode = SPI_DUALQUAD_REGULAR_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_ENABLE;
    pParam.eWriteTransCnt = 4;
    pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
    
    apSSP_WriteCmd(AHB_SSP0, 0, QSPI_STIG_CMD_WRITE);
    for (uint32_t i = 0; i < 4; ++i)
    {
        apSSP_WriteFIFO(AHB_SSP0, buf[i]);
    }
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
}

void rtl_gc9c01_qspi_write_buff0(uint8_t *buff, uint16_t size)
{
    pParam.eQuadMode = SPI_DUALQUAD_REGULAR_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_DISABLE;
    pParam.eWriteTransCnt = size;
    pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
    
    apSSP_WriteCmd(AHB_SSP0, 0, 0);
    for (uint32_t i = 0; i < size; ++i)
    {
        apSSP_WriteFIFO(AHB_SSP0, buff[i]);
    }
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
}
void rtl_gc9c01_qspi_write_buff_quad0(uint8_t *buff, uint16_t size)
{
    pParam.eQuadMode = SPI_DUALQUAD_QUAD_IO_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_DISABLE;
    pParam.eWriteTransCnt = size;
    pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

    apSSP_WriteCmd(AHB_SSP0, 0, 0);
    for(uint32_t i=0; i < size; i++)
    {
        apSSP_WriteFIFO(AHB_SSP0, buff[i]);
    }
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
}

void rt1_gc9c01_qspi_read_buff0(uint8_t *buff, uint16_t size)
{
    pParam.eQuadMode = SPI_DUALQUAD_REGULAR_MODE;
    pParam.eAddrEn = SPI_ADDREN_DISABLE;
    pParam.eCmdEn = SPI_CMDEN_DISABLE;
    pParam.eReadTransCnt = size;
    pParam.eReadWriteMode = SPI_TRANSMODE_READ_ONLY;
    apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

    apSSP_WriteCmd(AHB_SSP0, 0, 0);
    while(apSSP_GetSPIActiveStatus(AHB_SSP0));
    for (uint16_t i = 0; i < size; ++i)
    {
        apSSP_ReadFIFO(AHB_SSP0, (uint32_t *)&buff[i]);;
    }
}



static uint32_t peripherals_spi_isr(void *user_data)
{
  uint32_t stat = apSSP_GetIntRawStatus(AHB_SSP0);
  if(stat & (1 << bsSPI_INTREN_ENDINTEN))
  {
    apSSP_ClearIntStatus(AHB_SSP0, 1 << bsSPI_INTREN_ENDINTEN);
  }

  return 0;
}

#define SPI_HIGH_SPEED

static void setup_peripherals_spi_pin(void)
{
    SYSCTRL_ClearClkGateMulti(    (1 << SYSCTRL_ITEM_AHB_SPI0)
                                | (1 << SYSCTRL_ITEM_APB_PinCtrl));
    
    // Manual control CS pin

    PINCTRL_SelSpiIn(SPI_PORT_0, SPI_MIC_CLK, IO_NOT_A_PIN, SPI_MIC_HOLD,
                     SPI_MIC_WP, SPI_MIC_MISO, SPI_MIC_MOSI);
    PINCTRL_SetPadMux(SPI_MIC_CLK, IO_SOURCE_SPI0_CLK_OUT);
    //PINCTRL_SetPadMux(SPI_MIC_CS, IO_SOURCE_SPI0_CSN_OUT);
    PINCTRL_SetPadMux(SPI_MIC_MOSI, IO_SOURCE_SPI0_MOSI_OUT);
    PINCTRL_SetPadMux(SPI_MIC_MISO, IO_SOURCE_SPI0_MISO_OUT);
    PINCTRL_SetPadMux(SPI_MIC_WP, IO_SOURCE_SPI0_WP_OUT);
    PINCTRL_SetPadMux(SPI_MIC_HOLD, IO_SOURCE_SPI0_HOLD_OUT);
    
    PINCTRL_Pull(SPI_MIC_WP, PINCTRL_PULL_DOWN);
    PINCTRL_Pull(SPI_MIC_HOLD, PINCTRL_PULL_DOWN);

    platform_set_irq_callback(PLATFORM_CB_IRQ_AHPSPI, peripherals_spi_isr, NULL);
}

uint8_t setup_peripherals_spi_0_high_speed_interface_clk(uint32_t spiClk)
{
    //for spi0 only
    uint8_t eSclkDiv = 0;
    uint32_t spiIntfClk;
    uint32_t pllClk = SYSCTRL_GetPLLClk();
    
    SYSCTRL_SelectSpiClk(SPI_PORT_0,SYSCTRL_CLK_PLL_DIV_3);
    
    spiIntfClk = SYSCTRL_GetClk(SYSCTRL_ITEM_AHB_SPI0);
    eSclkDiv = ((spiIntfClk/spiClk)/2)-1;
    
    platform_printf("clk %d %d %d", spiIntfClk, spiClk, eSclkDiv);

    return eSclkDiv;
}

static void setup_peripherals_spi_module(void)
{
    #ifdef SPI_HIGH_SPEED
    pParam.eSclkDiv = setup_peripherals_spi_0_high_speed_interface_clk(56000000);
    #endif
}

void setup_peripherals_spi(void)
{
    setup_peripherals_spi_pin();
    setup_peripherals_spi_module();

    platform_printf(" setup clk %d \n", SYSCTRL_GetPLLClk());
}

