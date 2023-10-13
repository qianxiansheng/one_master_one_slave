/* $(license) */

/* 
 * more detail：
 *     https://ingchips.github.io/drafts/pg_ing916/ch-sysctrl.html
 *     https://ingchips.github.io/drafts/pg_ing916/ch-pinctrl.html
 *     https://ingchips.github.io/drafts/pg_ing916/ch-spi.html
 *     datasheet
 *
 * (1) normal SPI. TODO
 * (2) SPI DMA.
 * (3) high speed SPI (clock frequnce > 20Mbps).
 *     need to use SYSCtrl to switch spi clock source first
 * 
 */
 
#include "case_spi.h"

#include "semphr.h"
 
// SPI
#if CASE_QSPI

#define SSP_Ptr             AHB_SSP0

#define SPI_MIC_CLK         GIO_GPIO_19
#define SPI_MIC_CS          GIO_GPIO_18
#define SPI_MIC_MISO        GIO_GPIO_27
#define SPI_MIC_MOSI        GIO_GPIO_28
#define SPI_MIC_HOLD        GIO_GPIO_20
#define SPI_MIC_WP          GIO_GPIO_26

#define DATA_LEN_CNT_MAX_FOR_SPI (512)

uint32_t read_data[0x100] = {0};


void spi_set_data_size(uint8_t dataSize)
{
    apSSP_SetTransferFormat(SSP_Ptr, (dataSize - 1), bsSPI_TRANSFMT_DATALEN, bwSPI_TRANSFMT_DATALEN);
}
void spi_set_trans_cnt(uint32_t transCnt)
{
    apSSP_SetTransferControlWrTranCnt(SSP_Ptr, transCnt);
}

static uint32_t peripherals_spi_isr(void* user_data)
{
    uint32_t i = 0;
    uint32_t stat = apSSP_GetIntRawStatus(SSP_Ptr);
    
    if (stat & (1 << bsSPI_INTREN_ENDINTEN))
    {
        apSSP_ClearIntStatus(SSP_Ptr, 1 << bsSPI_INTREN_ENDINTEN);
        
        printf("end intent\n");
        
        uint32_t num = apSSP_GetDataNumInRxFifo(APB_SSP1);
        for(i = 0; i < num; i++)
        {
          apSSP_ReadFIFO(APB_SSP1, &read_data[i]);
        }
    }
    return 0;
}


void spi_config()
{
    SYSCTRL_ClearClkGateMulti((1 << SYSCTRL_ITEM_AHB_SPI0));
    PINCTRL_SelSpiIn(SPI_PORT_0, SPI_MIC_CLK, SPI_MIC_CS, SPI_MIC_HOLD, SPI_MIC_WP, SPI_MIC_MISO, SPI_MIC_MOSI);
    PINCTRL_SetPadMux(SPI_MIC_CLK, IO_SOURCE_SPI0_CLK_OUT);
    PINCTRL_SetPadMux(SPI_MIC_CS, IO_SOURCE_SPI0_CSN_OUT);
    PINCTRL_SetPadMux(SPI_MIC_MOSI, IO_SOURCE_SPI0_MOSI_OUT);
    PINCTRL_SetPadMux(SPI_MIC_MISO, IO_SOURCE_SPI0_MISO_OUT);
    PINCTRL_SetPadMux(SPI_MIC_WP, IO_SOURCE_SPI0_WP_OUT);
    PINCTRL_SetPadMux(SPI_MIC_HOLD, IO_SOURCE_SPI0_HOLD_OUT);
    
    PINCTRL_Pull(IO_SOURCE_SPI0_CLK_IN,PINCTRL_PULL_DOWN);
    PINCTRL_Pull(IO_SOURCE_SPI0_CSN_IN,PINCTRL_PULL_UP);
    
    platform_set_irq_callback(PLATFORM_CB_IRQ_AHPSPI, peripherals_spi_isr, NULL);
    
    apSSP_sDeviceControlBlock param;
    param.eSclkDiv         = (  SPI_InterfaceTimingSclkDiv )SPI_INTERFACETIMINGSCLKDIV_DEFAULT_2M;
    param.eSCLKPhase       = (  SPI_TransFmt_CPHA_e        )SPI_CPHA_ODD_SCLK_EDGES;
    param.eSCLKPolarity    = (  SPI_TransFmt_CPOL_e        )SPI_CPOL_SCLK_LOW_IN_IDLE_STATES;
    param.eLsbMsbOrder     = (  SPI_TransFmt_LSB_e         )SPI_LSB_MOST_SIGNIFICANT_BIT_FIRST;
    param.eDataSize        = (  SPI_TransFmt_DataLen_e     )SPI_DATALEN_8_BITS;
    param.eMasterSlaveMode = (  SPI_TransFmt_SlvMode_e     )SPI_SLVMODE_MASTER_MODE;
    param.eReadWriteMode   = (  SPI_TransCtrl_TransMode_e  )SPI_TRANSMODE_WRITE_DUMMY_READ;
    param.eQuadMode        = (  SPI_TransCtrl_DualQuad_e   )SPI_DUALQUAD_QUAD_IO_MODE;
    param.eWriteTransCnt   = (  SPI_TransCtrl_TransCnt     )1;
    param.eReadTransCnt    = (  SPI_TransCtrl_TransCnt     )1;
    param.eAddrEn          = (  SPI_TransCtrl_AddrEn_e     )SPI_ADDREN_ENABLE;
    param.eCmdEn           = (  SPI_TransCtrl_CmdEn_e      )SPI_CMDEN_ENABLE;
    param.eInterruptMask   = (  SPI_InterruptEnableMask    )(1 << bsSPI_INTREN_ENDINTEN);
    param.TxThres          = (  SPI_ControlTxThres         )1;
    param.RxThres          = (  SPI_ControlRxThres         )1;
    param.SlaveDataOnly    = (  SPI_TransCtrl_SlvDataOnly_e)SPI_SLVDATAONLY_DISABLE;
    param.eAddrLen         = (  SPI_TransFmt_AddrLen_e     )SPI_ADDRLEN_1_BYTE;
    
    apSSP_DeviceParametersSet(SSP_Ptr, &param);
}

void spi_test_init()
{
    SYSCTRL_ClearClkGateMulti((1 << SYSCTRL_ITEM_APB_SysCtrl)
                             |(1 << SYSCTRL_ITEM_APB_PinCtrl));
    
    spi_config();
}


uint32_t write_data[0x100] = {0};

void spi_test_timer_task(TimerHandle_t xTimer)
{
    int transCnt = 16;
    apSSP_SetTransferControlWrTranCnt(SSP_Ptr, transCnt);
    
    uint32_t i = 0;
    for(i = 0; i < transCnt; i++)
    {
        if(apSSP_TxFifoFull(SSP_Ptr)){ break; }
        apSSP_WriteFIFO(SSP_Ptr, write_data[i]);
    }
}

void spi_test()
{
    TimerHandle_t handle = xTimerCreate("spi",               //pcTimerName
                                        pdMS_TO_TICKS(1000), //xTimerPeriodInTicks
                                        pdFALSE,             //uxAutoReload
                                        NULL,                //pvTimerID
                                        spi_test_timer_task);//pxCallbackFunction
    xTimerStart(handle, portMAX_DELAY);
}

#endif
