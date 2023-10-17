#include <stdio.h>
#include <string.h>

#include "platform_api.h"
#include "FreeRTOS.h"
#include "task.h"

#define LCD_DEBUG platform_printf

#define RESET_PIN       23
#define LCD_RST_RELEASE GIO_WriteValue(RESET_PIN, 1);
#define LCD_RST_SET     GIO_WriteValue(RESET_PIN, 0);

#define CS_PIN          18
#define CS_ON           GIO_WriteValue(CS_PIN, 0);
#define CS_OFF          GIO_WriteValue(CS_PIN, 1);

extern void LCD_QSPI_inteface0(uint8_t cmd, uint8_t *param, uint8_t len);
extern void rtl_gc9c01_qspi_write_cmd0(const uint8_t cmd);
extern void rtl_gc9c01_qspi_write_cmd_quad0(const uint8_t cmd);
extern void rtl_gc9c01_qspi_cmd_param0(uint8_t cmd, uint8_t param);
extern void rtl_gc9c01_qspi_write_buff0(uint8_t *buff, uint16_t size);
extern void rtl_gc9c01_qspi_write_buff_quad0(uint8_t *buff, uint16_t size);
extern void rt1_gc9c01_qspi_read_buff0(uint8_t *buff, uint16_t size);

#define LCD_QSPI_inteface(cmd, param, len) { CS_ON LCD_QSPI_inteface0(cmd, param, len); CS_OFF }
#define rtl_gc9c01_qspi_write_cmd(cmd) { CS_ON rtl_gc9c01_qspi_write_cmd0(cmd); CS_OFF }
#define rtl_gc9c01_qspi_cmd_param(cmd, param) { CS_ON rtl_gc9c01_qspi_cmd_param0(cmd, param); CS_OFF }
#define rtl_gc9c01_qspi_write_buff(buff, size) { CS_ON rtl_gc9c01_qspi_write_buff0(buff, size); CS_OFF }
#define rt1_gc9c01_qspi_read_buff(buff, size) { CS_ON rt1_gc9c01_qspi_read_buff0(buff, size); CS_OFF }

#define rtl_gc9c01_qspi_write_cmd_quad rtl_gc9c01_qspi_write_cmd_quad0
#define rtl_gc9c01_qspi_write_buff_quad rtl_gc9c01_qspi_write_buff_quad0

#define co_delay_1ms(unit) vTaskDelay(pdMS_TO_TICKS(unit));

void lcd_gc9c01_read_manufacturer()
{
    uint8_t data[4];
    CS_ON
    rtl_gc9c01_qspi_write_cmd0(0x04);
    rt1_gc9c01_qspi_read_buff0(data, 4);
    CS_OFF
    platform_printf("manufacturer info: %x %x %x %x\n", data[0], data[1], data[2], data[3]);
}

void lcd_gc9c01_read_display_status()
{
    uint8_t data[5];
    CS_ON
    rtl_gc9c01_qspi_write_cmd0(0x09);
    rt1_gc9c01_qspi_read_buff0(data, 5);
    CS_OFF
    platform_printf("display status: %x %x %x %x %x\n", data[0], data[1], data[2], data[3], data[4]);
}

void lcd_gc9c01_set_windows(uint16_t x_s, uint16_t y_s, uint16_t x_e, uint16_t y_e)
{
    uint8_t axis_x[4] = {0x00,0x00,0x00,0x00};
    uint8_t axis_y[4] = {0x00,0x00,0x00,0x00};

    axis_x[0] = x_s>>8;
    axis_x[1] = x_s&0xff;
    axis_x[2] = x_e>>8;
    axis_x[3] = x_e&0xff;

    axis_y[0] = y_s>>8;
    axis_y[1] = y_s&0xff;
    axis_y[2] = y_e>>8;
    axis_y[3] = y_e&0xff;

    LCD_QSPI_inteface(0x2A, axis_x, 4);
    LCD_QSPI_inteface(0x2B, axis_y, 4);
}

#define QUAD_MODE
void lcd_display_start()
{
#ifdef QUAD_MODE
    rtl_gc9c01_qspi_write_cmd_quad(0x2c);
#else
    rtl_gc9c01_qspi_write_cmd0(0x2c);
#endif
}
void lcd_display(uint8_t *data, uint16_t size)
{
#ifdef QUAD_MODE
    rtl_gc9c01_qspi_write_buff_quad(data, size);
#else
    rtl_gc9c01_qspi_write_buff0(data, size);
#endif
}

void st7796h_draw_solid_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color)
{
	uint32_t 	len = width*height*2;
#define 	FILL_SIZE	512
	static uint8_t 	buf[FILL_SIZE];

	memset(buf,0,sizeof(buf));
	
	for(uint16_t i = 0; i < (FILL_SIZE/2); i++)	
	{
		buf[2*i+0] = (uint8_t)((color) >>8);
		buf[2*i+1] = (uint8_t)((color) & 0x00ff);
	}
    
	lcd_gc9c01_set_windows(x,y,x+width-1,y+height-1);
    
    CS_ON
    lcd_display_start();
	
	while(len >= (FILL_SIZE)) {
		len -= FILL_SIZE;//FILL_SIZE;
		lcd_display(buf,FILL_SIZE);
	}

	if(len) {
		lcd_display(buf,len);
		len = 0;
	}
    CS_OFF
}

void st7796h_draw_buffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *buffer)
{
	uint32_t 	len = width*height*2;
    uint32_t    total = len;
#define 	FILL_SIZE	512
	static uint8_t 	buf[FILL_SIZE];

	memset(buf,0,sizeof(buf));
    
	lcd_gc9c01_set_windows(x,y,x+width-1,y+height-1);
    
    CS_ON
    lcd_display_start();
	
	while(len >= (FILL_SIZE)) {
        memcpy(buf, buffer + (total - len), FILL_SIZE);
		len -= FILL_SIZE;//FILL_SIZE;
		lcd_display(buf,FILL_SIZE);
	}

	if(len) {
		lcd_display(buf,len);
		len = 0;
	}
    CS_OFF
}


#if 1
#define COLOR_WHITE			0xffff
#define COLOR_BLACK			0x0000
#define COLOR_R				0xF800
#define COLOR_G				0x07E0
#define COLOR_B				0x001F
#define COLOR_MAGENTA     	0xF81F
void am_fill_color(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color)
{
    st7796h_draw_solid_rect(x,y,width,height,color);
}

#define IMAGE_ADDR 0x2030000

void am_test_screen(void)
{
    while(1)
    {
        st7796h_draw_buffer(0, 0, 360, 360, (const uint8_t *)IMAGE_ADDR);
		co_delay_1ms(1000);//1s
        
		am_fill_color(0,0,360,360,COLOR_MAGENTA);
		co_delay_1ms(1000);//1s
		//am_fill_color(0,0,360,360,COLOR_R);
		//co_delay_1ms(1000);//1s
		//am_fill_color(0,0,360,360,COLOR_G);
		//co_delay_1ms(1000);//1s
		//am_fill_color(0,0,360,360,COLOR_B);
		//co_delay_1ms(1000);//1s
		//am_fill_color(0,0,360,360,COLOR_WHITE);
		//co_delay_1ms(1000);//1s
		//am_fill_color(0,0,360,360,COLOR_BLACK);
		//co_delay_1ms(1000);//1s
    }
}
#endif


static void lcm_reset(void)
{
    LCD_RST_RELEASE;
    co_delay_1ms(120);
    LCD_RST_SET;
    co_delay_1ms(100);
    LCD_RST_RELEASE;
    co_delay_1ms(120);
}

static void lcm_gc9c01_init(void)
{
    uint8_t dat[45] = {0x02, 0x00};

    rtl_gc9c01_qspi_write_cmd(0xfe);
    rtl_gc9c01_qspi_write_cmd(0xef);// internal reg enable
    rtl_gc9c01_qspi_cmd_param(0x80, 0x11);
    rtl_gc9c01_qspi_cmd_param(0x81, 0x70);//reg_en for 7C\7D\7E
    rtl_gc9c01_qspi_cmd_param(0x82, 0x09);//reg_en for 90\93
    rtl_gc9c01_qspi_cmd_param(0x83, 0x03);//reg_en for 98\99
    rtl_gc9c01_qspi_cmd_param(0x84, 0x20);//reg_en for B5
    rtl_gc9c01_qspi_cmd_param(0x85, 0x42);//reg_en for B9\BE
    rtl_gc9c01_qspi_cmd_param(0x86, 0xfc);//reg_en for C2~7
    rtl_gc9c01_qspi_cmd_param(0x87, 0x09);//reg_en for C8\CB
    rtl_gc9c01_qspi_cmd_param(0x89, 0x10);//reg_en for EC
    rtl_gc9c01_qspi_cmd_param(0x8A, 0x4f);//reg_en for F0~3\F6
    rtl_gc9c01_qspi_cmd_param(0x8C, 0x59);//reg_en for 60\63\64\66
    rtl_gc9c01_qspi_cmd_param(0x8D, 0x51);//reg_en for 68\6C\6E
    rtl_gc9c01_qspi_cmd_param(0x8E, 0xae);//reg_en for A1~3\A5\A7
    rtl_gc9c01_qspi_cmd_param(0x8F, 0xf3);//reg_en for AC~F\A8\A9

    rtl_gc9c01_qspi_cmd_param(0x36, 0x00);
    rtl_gc9c01_qspi_cmd_param(0x3a, 0x05);// 565 frame
    rtl_gc9c01_qspi_cmd_param(0xEC, 0x77);//2COL

    dat[2] = 0x74;
    dat[3] = 0x00;
    dat[4] = 0x01;
    dat[5] = 0x80;
    dat[6] = 0x00;
    dat[7] = 0x00;
    dat[8] = 0x00;
    dat[9] = 0x00;
    rtl_gc9c01_qspi_write_buff(dat, 10);//rtn 60Hz

    rtl_gc9c01_qspi_cmd_param(0x98, 0x3E);//bvdd 3x
    rtl_gc9c01_qspi_cmd_param(0x99, 0x3E);//bvee -2x

    rtl_gc9c01_qspi_cmd_param(0xC3, 0x2A);//VBP
    rtl_gc9c01_qspi_cmd_param(0xC4, 0x18);//VBN

    dat[2] = 0xA1;
    dat[3] = 0x00;
    dat[4] = 0x01;
    dat[5] = 0x04;
    rtl_gc9c01_qspi_write_buff(dat, 6);

    dat[2] = 0xA2;
    dat[3] = 0x00;
    dat[4] = 0x01;
    dat[5] = 0x04;
    rtl_gc9c01_qspi_write_buff(dat, 6);

    rtl_gc9c01_qspi_cmd_param(0xA9, 0x1C);//IREF

    dat[2] = 0xA5;
    dat[3] = 0x00;
    dat[4] = 0x11;//VDDMA
    dat[5] = 0x09;//VDDML
    rtl_gc9c01_qspi_write_buff(dat, 6);

    rtl_gc9c01_qspi_cmd_param(0xB9, 0x8A);//RTERM
    rtl_gc9c01_qspi_cmd_param(0xA8, 0x5E);//VBG_BUF, DVDD
    rtl_gc9c01_qspi_cmd_param(0xA7, 0x40);
    rtl_gc9c01_qspi_cmd_param(0xAF, 0x73);//VDDSOU ,VDDGM
    rtl_gc9c01_qspi_cmd_param(0xAE, 0x44);//VREE,VRDD
    rtl_gc9c01_qspi_cmd_param(0xAD, 0x38);//VRGL ,VDDSF
    rtl_gc9c01_qspi_cmd_param(0xA3, 0x5D);
    rtl_gc9c01_qspi_cmd_param(0xC2, 0x02);//VREG_VREF
    rtl_gc9c01_qspi_cmd_param(0xC5, 0x11);//VREG1A
    rtl_gc9c01_qspi_cmd_param(0xC6, 0x0E);//VREG1B
    rtl_gc9c01_qspi_cmd_param(0xC7, 0x13);//VREG2A
    rtl_gc9c01_qspi_cmd_param(0xC8, 0x0D);//VREG2B

    rtl_gc9c01_qspi_cmd_param(0xCB, 0x02);//bvdd ref_ad

    dat[2] = 0x7C;
    dat[3] = 0x00;
    dat[4] = 0xB6;
    dat[5] = 0x26;
    rtl_gc9c01_qspi_write_buff(dat, 6);

    rtl_gc9c01_qspi_cmd_param(0xAC, 0x24);//VGLO

    rtl_gc9c01_qspi_cmd_param(0xF6, 0x80);//EPF=2
    //*********************校准结束*************************//
    //gip start
    dat[2] = 0xB5;
    dat[3] = 0x00;
    dat[4] = 0x09;//VFP
    dat[5] = 0x09;//VBP
    rtl_gc9c01_qspi_write_buff(dat, 6);

    dat[2] = 0x60;
    dat[3] = 0x00;
    dat[4] = 0x38;
    dat[5] = 0x0B;
    dat[6] = 0x5B;
    dat[7] = 0x56;
    rtl_gc9c01_qspi_write_buff(dat, 8);//STV1&2

    dat[2] = 0x63;
    dat[3] = 0x00;
    dat[4] = 0x3A;
    dat[5] = 0xE0;//DE
    dat[6] = 0x5B;//MAX=0x61
    dat[7] = 0x56;//MAX=0x61
    rtl_gc9c01_qspi_write_buff(dat, 8);

    dat[2] = 0x64;
    dat[3] = 0x00;
    dat[4] = 0x38;
    dat[5] = 0x0D;
    dat[6] = 0x72;
    dat[7] = 0xDD;
    dat[8] = 0x5B;
    dat[9] = 0x56;
    rtl_gc9c01_qspi_write_buff(dat, 10);//CLK_group1

    dat[2] = 0x66;
    dat[3] = 0x00;
    dat[4] = 0x38;
    dat[5] = 0x11;
    dat[6] = 0x72;
    dat[7] = 0xE1;
    dat[8] = 0x5B;
    dat[9] = 0x56;
    rtl_gc9c01_qspi_write_buff(dat, 10);//CLK_group1

    dat[2] = 0x68;
    dat[3] = 0x00;
    dat[4] = 0x3B;//FLC12 FREQ
    dat[5] = 0x08;
    dat[6] = 0x08;
    dat[7] = 0x00;
    dat[8] = 0x08;
    dat[9] = 0x29;
    dat[10] = 0x5B;
    rtl_gc9c01_qspi_write_buff(dat, 11);//FLC&FLV 1~2

    dat[2] = 0x6E;
    dat[3] = 0x00;
    dat[4] = 0x00;
    dat[5] = 0x00;
    dat[6] = 0x00;
    dat[7] = 0x07;
    dat[8] = 0x01;
    dat[9] = 0x13;
    dat[10] = 0x11;
    dat[11] = 0x0B;
    dat[12] = 0x09;
    dat[13] = 0x16;
    dat[14] = 0x15;
    dat[15] = 0x1D;
    dat[16] = 0x1E;
    dat[17] = 0x00;
    dat[18] = 0x00;
    dat[19] = 0x00;
    dat[20] = 0x00;
    dat[21] = 0x00;
    dat[22] = 0x00;
    dat[23] = 0x1E;
    dat[24] = 0x1D;
    dat[25] = 0x15;
    dat[26] = 0x16;
    dat[27] = 0x0A;
    dat[28] = 0x0C;
    dat[29] = 0x12;
    dat[30] = 0x14;
    dat[31] = 0x02;
    dat[32] = 0x08;
    dat[33] = 0x00;
    dat[34] = 0x00;
    dat[35] = 0x00;
    rtl_gc9c01_qspi_write_buff(dat, 36);//gip end

    rtl_gc9c01_qspi_cmd_param(0xBE, 0x11);//SOU_BIAS_FIX

    dat[2] = 0x6C;
    dat[3] = 0x00;
    dat[4] = 0xCC;
    dat[5] = 0x0C;
    dat[6] = 0xCC;
    dat[7] = 0x84;
    dat[8] = 0xCC;
    dat[9] = 0x04;
    dat[10] = 0x50;
    rtl_gc9c01_qspi_write_buff(dat, 11);//precharge GATE

    rtl_gc9c01_qspi_cmd_param(0x7D, 0x72);
    rtl_gc9c01_qspi_cmd_param(0x7E, 0x38);

    dat[2] = 0x70;
    dat[3] = 0x00;
    dat[4] = 0x02;
    dat[5] = 0x03;
    dat[6] = 0x09;
    dat[7] = 0x05;
    dat[8] = 0x0C;
    dat[9] = 0x06;
    dat[10] = 0x09;
    dat[11] = 0x05;
    dat[12] = 0x0C;
    dat[13] = 0x06;
    rtl_gc9c01_qspi_write_buff(dat, 14);

    dat[2] = 0x90;
    dat[3] = 0x00;
    dat[4] = 0x06;
    dat[5] = 0x06;
    dat[6] = 0x05;
    dat[7] = 0x06;
    rtl_gc9c01_qspi_write_buff(dat, 8);

    dat[2] = 0x93;
    dat[3] = 0x00;
    dat[4] = 0x45;
    dat[5] = 0xFF;
    dat[6] = 0x00;
    rtl_gc9c01_qspi_write_buff(dat, 7);

    dat[2] = 0xF0;
    dat[3] = 0x00;
    dat[4] = 0x45;
    dat[5] = 0x09;
    dat[6] = 0x08;
    dat[7] = 0x08;
    dat[8] = 0x26;
    dat[9] = 0x2A;
    rtl_gc9c01_qspi_write_buff(dat, 10);//gamma start

    dat[2] = 0xF1;
    dat[3] = 0x00;
    dat[4] = 0x43;
    dat[5] = 0x70;
    dat[6] = 0x72;
    dat[7] = 0x36;
    dat[8] = 0x37;
    dat[9] = 0x6F;
    rtl_gc9c01_qspi_write_buff(dat, 10);

    dat[2] = 0xF2;
    dat[3] = 0x00;
    dat[4] = 0x45;
    dat[5] = 0x09;
    dat[6] = 0x08;
    dat[7] = 0x08;
    dat[8] = 0x26;
    dat[9] = 0x2A;
    rtl_gc9c01_qspi_write_buff(dat, 10);

    dat[2] = 0xF3;
    dat[3] = 0x00;
    dat[4] = 0x43;
    dat[5] = 0x70;
    dat[6] = 0x72;
    dat[7] = 0x36;
    dat[8] = 0x37;
    dat[9] = 0x6F;
    rtl_gc9c01_qspi_write_buff(dat, 10);//gamma end

    //rtl_gc9c01_qspi_cmd_param(0x35, 0x00);

    rtl_gc9c01_qspi_write_cmd(0xfe);

    rtl_gc9c01_qspi_write_cmd(0xee);

    rtl_gc9c01_qspi_write_cmd(0x11);
    co_delay_1ms(12);
    rtl_gc9c01_qspi_write_cmd(0x29);
}

// LCD 屏初始化
void lcd_gc9c01_init(void)
{
	LCD_DEBUG("lcm init entry1\r\n");

    lcm_reset();
    lcm_gc9c01_init();
    co_delay_1ms(100);
    lcd_gc9c01_read_manufacturer();
    lcd_gc9c01_read_display_status();
    LCD_DEBUG("lcm init back\r\n");
}
