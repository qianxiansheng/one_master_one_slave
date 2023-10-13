#include <stdio.h>
#include <string.h>
#include "profile.h"
#include "ingsoc.h"
#include "platform_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "trace.h"
#include "timers.h"

// ============================ static definition ===============================
#define SPI_MIC_CLK         GIO_GPIO_7
#define SPI_MIC_MOSI        GIO_GPIO_8
#define SPI_MIC_MISO        GIO_GPIO_9
#define SPI_MIC_CS          GIO_GPIO_10
#define SPI_MIC_WP          GIO_GPIO_11
#define SPI_MIC_HOLD        GIO_GPIO_12

enum{STATUS_REG_1_BUSY = 0,};
enum{STATUS_REG_1 = 0x05, STATUS_REG_2 = 0x35, STATUS_REG_3 = 0x15};

/* init SPI config */
#define SPI_MASTER_PARAM { SPI_INTERFACETIMINGSCLKDIV_DEFAULT_2M, \
SPI_CPHA_ODD_SCLK_EDGES, SPI_CPOL_SCLK_LOW_IN_IDLE_STATES, \
SPI_LSB_MOST_SIGNIFICANT_BIT_FIRST, SPI_DATALEN_8_BITS, SPI_SLVMODE_MASTER_MODE, \
SPI_TRANSMODE_WRITE_ONLY, SPI_DUALQUAD_QUAD_IO_MODE, 1, 1, \
SPI_ADDREN_ENABLE, SPI_CMDEN_ENABLE, (1 << bsSPI_INTREN_ENDINTEN), \
0, 0, SPI_SLVDATAONLY_DISABLE, SPI_ADDRLEN_3_BYTES }

apSSP_sDeviceControlBlock pParam = SPI_MASTER_PARAM;

#define QUAD_MODE // SINGLE_MODE
// ============================ functions ===============================

static uint32_t peripherals_spi_isr(void *user_data)
{
  uint32_t stat = apSSP_GetIntRawStatus(AHB_SSP0);
  if(stat & (1 << bsSPI_INTREN_ENDINTEN))
  {
    apSSP_ClearIntStatus(AHB_SSP0, 1 << bsSPI_INTREN_ENDINTEN);
  }

  return 0;
}

static uint32_t W25QXX_read_manufacturer(void)
{
  uint8_t data[2];
  pParam.eQuadMode       = SPI_DUALQUAD_REGULAR_MODE;   // 单线模式
  pParam.eAddrEn         = SPI_ADDREN_ENABLE;           // 使用地址
  pParam.eCmdEn          = SPI_CMDEN_ENABLE;            // 使用指令
  pParam.eReadTransCnt   = 2;                           // 读取2字节数据
  pParam.eReadWriteMode  = SPI_TRANSMODE_READ_ONLY;     // 只读模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

  apSSP_WriteCmd(AHB_SSP0, 0, 0x90);                    // 传输指令0x90和地址0，指令看手册定义
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 没用DMA，等待SPI传输结束
  apSSP_ReadFIFO(AHB_SSP0, (uint32_t*)&data[0]);        // 读取返回数据
  apSSP_ReadFIFO(AHB_SSP0, (uint32_t*)&data[1]);        // 读取返回数据
  return *(uint32_t*)data;
}

static uint8_t W25QXX_read_status(uint32_t reg)
{
  uint32_t status       = 0;                            
  pParam.eQuadMode      = SPI_DUALQUAD_REGULAR_MODE;    // 单线模式
  pParam.eAddrEn        = SPI_ADDREN_DISABLE;           // 禁用地址
  pParam.eCmdEn         = SPI_CMDEN_ENABLE;             // 使用指令（会先用单线模式传输指令）
  pParam.eReadTransCnt  = 1;                            // 读取1个字节
  pParam.eReadWriteMode = SPI_TRANSMODE_READ_ONLY;      // 只读模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

  apSSP_WriteCmd(AHB_SSP0, 0, reg);                     // 传输指令，指令看Flash手册定义
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 没用DMA，等待SPI传输结束
  apSSP_ReadFIFO(AHB_SSP0, &status);                    // 从SPI FIFO中读取Flash模块返回的数据
  
  return status;
}

static void W25QXX_write_enable(void)
{
  pParam.eQuadMode      = SPI_DUALQUAD_REGULAR_MODE;    // 单线模式
  pParam.eAddrEn        = SPI_ADDREN_DISABLE;           // 禁用地址
  pParam.eCmdEn         = SPI_CMDEN_ENABLE;             // 使用指令
  pParam.eReadWriteMode = SPI_TRANSMODE_NONE_DATA;      // 无数据模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
  
  apSSP_WriteCmd(AHB_SSP0, 0, 0x06);                    // 传输指令0x06，指令看Flash手册定义
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 等待传输结束
}

static void W25QXX_sector_erase_flash(uint32_t addr)
{
  W25QXX_write_enable();        // 先传输指令使能Flash模块的写入（写入保护）
  
  pParam.eQuadMode      = SPI_DUALQUAD_REGULAR_MODE;    // 单线模式
  pParam.eAddrEn        = SPI_ADDREN_ENABLE;            // 使用地址
  pParam.eCmdEn         = SPI_CMDEN_ENABLE;             // 使用指令
  pParam.eAddrLen       = SPI_ADDRLEN_3_BYTES;          // 地址长度3Bytes
  pParam.eReadWriteMode = SPI_TRANSMODE_NONE_DATA;      // 无数据模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);
  
  apSSP_WriteCmd(AHB_SSP0, addr&0xffffff, 0x20);        // 写入指令0x20，写入地址addr
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 等待传输结束
  while(W25QXX_read_status(STATUS_REG_1)&(1<<STATUS_REG_1_BUSY));
}

static void W25QXX_write_status(uint32_t reg, uint8_t data)
{
  W25QXX_write_enable();        // 先传输指令使能Flash模块的写入（写入保护）
  
  pParam.eQuadMode      = SPI_DUALQUAD_REGULAR_MODE;    // 单线模式
  pParam.eAddrEn        = SPI_ADDREN_DISABLE;           // 禁用地址
  pParam.eCmdEn         = SPI_CMDEN_ENABLE;             // 使用指令
  pParam.eWriteTransCnt = 1;                            // 写1字节数据
  pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;     // 只写模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

  apSSP_WriteCmd(AHB_SSP0, 0, 0x20);                    // 传输指令，指令看手册定义
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 没用DMA，等待SPI传输结束
    
  // 循环地查询Flash模块的状态寄存器，当busy位为0时，表示Flash模块已处理完指令，查忙flash模块
  while(W25QXX_read_status(STATUS_REG_1)&(1<<STATUS_REG_1_BUSY));
}

static void W25QXX_page_program_single_mode(uint32_t addr, uint8_t *data, uint32_t len)
{
  W25QXX_write_enable();        // 先传输指令使能Flash模块的写入（写入保护）
  
  pParam.eQuadMode      = SPI_DUALQUAD_REGULAR_MODE;    // 单线模式
  pParam.eAddrEn        = SPI_ADDREN_ENABLE;            // 使用地址
  pParam.eCmdEn         = SPI_CMDEN_ENABLE;             // 使用指令
  pParam.eAddrLen       = SPI_ADDRLEN_3_BYTES;          // 地址部分长度3Bytes
  pParam.eWriteTransCnt = len;                          // 数据部分长度
  pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;     // 只写模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

  apSSP_WriteCmd(AHB_SSP0, addr&0xffffff, 0x02);        // 写入指令0x02，写入地址addr
  for(uint32_t i=0; i < len; i++)                       // 写入数据
  {
    apSSP_WriteFIFO(AHB_SSP0, data[i]);
  }
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 等待传输结束
  while(W25QXX_read_status(STATUS_REG_1)&(1<<STATUS_REG_1_BUSY));   //查忙flash模块
}

static void W25QXX_page_program_quad_mode(uint32_t addr, uint8_t *data, uint32_t len)
{
  W25QXX_write_enable();        // 先传输指令使能Flash模块的写入（写入保护）
  
  pParam.eQuadMode      = SPI_DUALQUAD_QUAD_IO_MODE;    // 四线模式
  pParam.eAddrEn        = SPI_ADDREN_ENABLE;            // 使用地址
  pParam.eCmdEn         = SPI_CMDEN_ENABLE;             // 使用指令
  pParam.eAddrLen       = SPI_ADDRLEN_3_BYTES;          // 地址长度为3bytes
  pParam.eWriteTransCnt = len;                          // 传输N字节数据
  pParam.eReadWriteMode = SPI_TRANSMODE_WRITE_ONLY;     // 只写模式
  apSSP_DeviceParametersSet(AHB_SSP0, &pParam);

  apSSP_WriteCmd(AHB_SSP0, addr&0xffffff, 0x32);        // 写入指令0x32，写入地址addr
  for(uint32_t i=0; i < len; i++)                       // 写入数据
  {
    apSSP_WriteFIFO(AHB_SSP0, data[i]);
  }
  while(apSSP_GetSPIActiveStatus(AHB_SSP0));            // 等待传输结束
  while(W25QXX_read_status(STATUS_REG_1)&(1<<STATUS_REG_1_BUSY));   //查忙flash模块
}

void peripherals_spi_send_data(void)
{
  printf("manufacturer 0x%x \n",W25QXX_read_manufacturer());
  printf("status 0x%x 0x%x 0x%x\n",W25QXX_read_status(STATUS_REG_1),W25QXX_read_status(STATUS_REG_2),W25QXX_read_status(STATUS_REG_3));

  W25QXX_sector_erase_flash(0);

  uint8_t data[256];memset(data, 0x37, sizeof(data));
  
  // write to flash
  #ifdef QUAD_MODE
  W25QXX_page_program_quad_mode(0, data, sizeof(data));
  #else
  W25QXX_page_program_single_mode(0, data, sizeof(data));
  #endif

  // read from flash
  #ifdef QUAD_MODE
  apSSP_SetMemAccessCmd(AHB_SSP0,SPI_MEMRD_CMD_6B);
  #else
  apSSP_SetMemAccessCmd(AHB_SSP0,SPI_MEMRD_CMD_03);
  #endif
  printf("read back: ");for(uint32_t i=0; i < 256/4; i++){printf("%x, ", *((uint32_t*)AHB_QSPI_MEM_BASE+i));};printf("\n");

}

static void setup_peripherals_spi_pin(void)
{
    SYSCTRL_ClearClkGateMulti(    (1 << SYSCTRL_ITEM_AHB_SPI0)
                                | (1 << SYSCTRL_ITEM_APB_PinCtrl));

    PINCTRL_SelSpiIn(SPI_PORT_0, SPI_MIC_CLK, SPI_MIC_CS, SPI_MIC_HOLD,
                     SPI_MIC_WP, SPI_MIC_MISO, SPI_MIC_MOSI);
    PINCTRL_SetPadMux(SPI_MIC_CLK, IO_SOURCE_SPI0_CLK_OUT);
    PINCTRL_SetPadMux(SPI_MIC_CS, IO_SOURCE_SPI0_CSN_OUT);
    PINCTRL_SetPadMux(SPI_MIC_MOSI, IO_SOURCE_SPI0_MOSI_OUT);
    PINCTRL_SetPadMux(SPI_MIC_MISO, IO_SOURCE_SPI0_MISO_OUT);
    PINCTRL_SetPadMux(SPI_MIC_WP, IO_SOURCE_SPI0_WP_OUT);
    PINCTRL_SetPadMux(SPI_MIC_HOLD, IO_SOURCE_SPI0_HOLD_OUT);

    platform_set_irq_callback(PLATFORM_CB_IRQ_AHPSPI, peripherals_spi_isr, NULL);
}

uint8_t setup_peripherals_spi_0_high_speed_interface_clk(uint32_t spiClk)
{
    //for spi0 only
    uint8_t eSclkDiv = 0;
    uint32_t spiIntfClk;
    uint32_t pllClk = SYSCTRL_GetPLLClk();
    
    SYSCTRL_SelectSpiClk(SPI_PORT_0,SYSCTRL_CLK_PLL_DIV_1+1);
    
    spiIntfClk = SYSCTRL_GetClk(SYSCTRL_ITEM_AHB_SPI0);
    eSclkDiv = ((spiIntfClk/spiClk)/2)-1;

    return eSclkDiv;
}

static void setup_peripherals_spi_module(void)
{
    #ifdef SPI_HIGH_SPEED
    pParam.eSclkDiv = setup_peripherals_spi_0_high_speed_interface_clk(21000000);
    #endif
}

void setup_peripherals_spi(void)
{
    setup_peripherals_spi_pin();
    setup_peripherals_spi_module();

    platform_printf(" setup clk %d \n", SYSCTRL_GetPLLClk());
}

