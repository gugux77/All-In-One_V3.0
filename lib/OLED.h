#include "Codetable.h"

#define Brightness 0xCF
#define X_WIDTH 128
#define Y_WIDTH 64
//#define SDA 1
//#define SCL 0

void IIC_Start(void)
{
	set_bit(PORTD, 0);
	set_bit(PORTD, 4);
	reset_bit(PORTD, 4);
	reset_bit(PORTD, 0);
}

void IIC_Stop(void)
{
	reset_bit(PORTD, 0);
	reset_bit(PORTD, 4);
	set_bit(PORTD, 0);
	set_bit(PORTD, 4);
}

// 通过I2C总线写一个字节
void Write_IIC_Byte(char IIC_Byte)
{
	unsigned char i;
	for (i = 0; i < 8; i++)
	{
		if (IIC_Byte & 0x80)
			set_bit(PORTD, 4);
		else
			reset_bit(PORTD, 4);
		set_bit(PORTD, 0);
		reset_bit(PORTD, 0);
		IIC_Byte <<= 1;
	}
	_delay_us(1);
	set_bit(PORTD, 4);
	set_bit(PORTD, 0);
	reset_bit(PORTD, 0);
}

/*
void IIC_Start(void)
{
	set_bit(PORTD, 0);
	set_bit(PORTD, 4);
	reset_bit(PORTD, 4);
	reset_bit(PORTD, 0);
}

void IIC_Stop(void)
{
	reset_bit(PORTD, 0);
	reset_bit(PORTD, 4);
	set_bit(PORTD, 0);
	set_bit(PORTD, 4);
}

// 通过I2C总线写一个字节
void Write_IIC_Byte(char IIC_Byte)
{
	unsigned char i;
	for (i = 0; i < 8; i++)
	{
		if (IIC_Byte & 0x80)
			set_bit(PORTD, 4);
		else
			reset_bit(PORTD, 4);
		set_bit(PORTD, 0);
		reset_bit(PORTD, 0);
		IIC_Byte <<= 1;
	}
	set_bit(PORTD, 4);
	set_bit(PORTD, 0);
	reset_bit(PORTD, 0);
}
*/

//OLED写数据
void OLED_WrDat(char IIC_Data)
{
	IIC_Start();
	Write_IIC_Byte(0x78);
	Write_IIC_Byte(0x40);
	Write_IIC_Byte(IIC_Data);
	IIC_Stop();
}

//OLED写命令
void OLED_WrCmd(char IIC_Command)
{
	IIC_Start();
	Write_IIC_Byte(0x78);
	Write_IIC_Byte(0x00);
	Write_IIC_Byte(IIC_Command);
	IIC_Stop();
}

//设置坐标
void OLED_Set_Pos(char x, char y)
{
	OLED_WrCmd(0xb0 + y);
	OLED_WrCmd(((x & 0xf0) >> 4) | 0x10);
	OLED_WrCmd((x & 0x0f) | 0x00);
}

//OLED全屏
void OLED_Fill(char bmp_dat)
{
	unsigned char y, x;
	for (y = 0; y < 8; y++)
	{
		OLED_WrCmd(0xb0 + y);
		OLED_WrCmd(0x00);
		OLED_WrCmd(0x10);
		for (x = 0; x < X_WIDTH; x++)
			OLED_WrDat(bmp_dat);
	}
}

//OLED复位
void OLED_CLS(void)
{
	unsigned char y, x;
	for (y = 0; y < 8; y++)
	{
		OLED_WrCmd(0xb0 + y);
		OLED_WrCmd(0x00);
		OLED_WrCmd(0x10);
		for (x = 0; x < X_WIDTH; x++)
			OLED_WrDat(0);
	}
}

//OLED初始化
void OLED_Init(void)
{
	cli();
	delay(500);
	OLED_WrCmd(0xae);
	OLED_WrCmd(0x00);
	OLED_WrCmd(0x10);
	OLED_WrCmd(0x40);
	OLED_WrCmd(0x81);
	OLED_WrCmd(Brightness);
	OLED_WrCmd(0xa1);
	OLED_WrCmd(0xc8);
	OLED_WrCmd(0xa6);
	OLED_WrCmd(0xa8);
	OLED_WrCmd(0x3f);
	OLED_WrCmd(0xd3);
	OLED_WrCmd(0x00);
	OLED_WrCmd(0xd5);
	OLED_WrCmd(0x80);
	OLED_WrCmd(0xd9);
	OLED_WrCmd(0xf1);
	OLED_WrCmd(0xda);
	OLED_WrCmd(0x12);
	OLED_WrCmd(0xdb);
	OLED_WrCmd(0x40);
	OLED_WrCmd(0x20);
	OLED_WrCmd(0x02);
	OLED_WrCmd(0x8d);
	OLED_WrCmd(0x14);
	OLED_WrCmd(0xa4);
	OLED_WrCmd(0xa6);
	OLED_WrCmd(0xaf);
	OLED_Fill(0x00);
	OLED_Set_Pos(0, 0);
	OLED_CLS();
	OLED_WrCmd(0xb0 + 6);
	OLED_WrCmd(((0 & 0xf0) >> 4) | 0x10);
	OLED_WrCmd((0 & 0x0f) | 0x00);
    OLED_WrDat(0x00);
	OLED_WrDat(0x3e);
	OLED_WrDat(0x41);
	OLED_WrDat(0x49);
	OLED_WrDat(0x49);
	OLED_WrDat(0x7a);
	OLED_WrDat(0x00);
	OLED_WrDat(0x7f);
	OLED_WrDat(0x04);
	OLED_WrDat(0x08);
	OLED_WrDat(0x10);
	OLED_WrDat(0x7f);
	OLED_WrDat(0x00);
	OLED_WrDat(0x3f);
	OLED_WrDat(0x40);
	OLED_WrDat(0x40);
	OLED_WrDat(0x40);
	OLED_WrDat(0x3f);
	OLED_WrDat(0x00);
	OLED_WrDat(0x00);
	OLED_WrDat(0x00);
	OLED_WrDat(0x00);
	OLED_WrDat(0x00);
	OLED_WrDat(0x00);
	OLED_WrDat(0x00);
	OLED_WrDat(0x7c);
	OLED_WrDat(0x12);
	OLED_WrDat(0x11);
	OLED_WrDat(0x12);
	OLED_WrDat(0x7c);
	OLED_WrDat(0x00);
	OLED_WrDat(0x3e);
	OLED_WrDat(0x41);
	OLED_WrDat(0x49);
	OLED_WrDat(0x49);
	OLED_WrDat(0x7a);
	OLED_WrDat(0x00);
	OLED_WrDat(0x7f);
	OLED_WrDat(0x09);
	OLED_WrDat(0x09);
	OLED_WrDat(0x06);
	OLED_WrDat(0x00);
	OLED_WrDat(0x7f);
	OLED_WrDat(0x40);
	OLED_WrDat(0x40);
	OLED_WrDat(0x40);
	OLED_WrDat(0x40);
	OLED_WrDat(0x00);
	OLED_WrDat(0x1c);
	OLED_WrDat(0x20);
	OLED_WrDat(0x40);
	OLED_WrDat(0x20);
	OLED_WrDat(0x1c);
	OLED_WrDat(0x00);
	OLED_WrDat(0x21);
	OLED_WrDat(0x41);
	OLED_WrDat(0x45);
	OLED_WrDat(0x4b);
	OLED_WrDat(0x31);
	OLED_WrCmd(0xb0 + 7);
	OLED_WrCmd(((1 & 0xf0) >> 4) | 0x10);
	OLED_WrCmd((1 & 0x0f) | 0x00);
    OLED_WrDat(0b00111100);
	OLED_WrDat(0b01000010);
	OLED_WrDat(0b10011001);
	OLED_WrDat(0b10100101);
	OLED_WrDat(0b10100101);
	OLED_WrDat(0b01000010);
	OLED_WrDat(0b00111100);
	OLED_WrDat(0x00);
	OLED_WrDat(0x3e);
	OLED_WrDat(0x41);
	OLED_WrDat(0x41);
	OLED_WrDat(0x41);
	OLED_WrDat(0x22);
	OLED_WrDat(0x00);
	OLED_WrDat(0x20);
	OLED_WrDat(0x54);
	OLED_WrDat(0x54);
	OLED_WrDat(0x54);
	OLED_WrDat(0x78);
	OLED_WrDat(0x00);
	OLED_WrDat(0x38);
	OLED_WrDat(0x44);
	OLED_WrDat(0x44);
	OLED_WrDat(0x44);
	OLED_WrDat(0x38);
	OLED_WrDat(0x00);
	OLED_WrDat(0x20);
	OLED_WrDat(0x40);
	OLED_WrDat(0x41);
	OLED_WrDat(0x3f);
	OLED_WrDat(0x01);
	OLED_WrDat(0x00);
	OLED_WrDat(0x3c);
	OLED_WrDat(0x40);
	OLED_WrDat(0x40);
	OLED_WrDat(0x20);
	OLED_WrDat(0x7c);
	sei();
}

//显示6*8 ASCII字符串 坐标x,y y为页范围0~7
void OLED_P6x8Str(char x, char y, char ch[])
{
	unsigned char c = 0, i = 0, j = 0;
	while (ch[j] != '\0')
	{
		c = ch[j] - 32;
		if (x > 126)
		{
			x = 0;
			y++;
		}
		OLED_Set_Pos(x, y);
		for (i = 0; i < 6; i++)
			OLED_WrDat(pgm_read_byte(&F6x8[c][i]));
		x += 6;
		j++;
	}
}

//显示8*16 ASCII字符串 显示的坐标x,y y为页范围0~7
void OLED_P8x16Str(char x, char y, char ch[])
{
	unsigned char c = 0, i = 0, j = 0;
	while (ch[j] != '\0')
	{
		c = ch[j] - 32;
		if (x > 120)
		{
			x = 0;
			y++;
		}
		OLED_Set_Pos(x, y);
		for (i = 0; i < 8; i++)
			OLED_WrDat(pgm_read_byte(&F8X16[c * 16 + i]));
		OLED_Set_Pos(x, y + 1);
		for (i = 0; i < 8; i++)
			OLED_WrDat(pgm_read_byte(&F8X16[c * 16 + i + 8]));
		x += 8;
		j++;
	}
}

//显示16*16点阵 显示的坐标x,y y为页范围0~7
void OLED_P16x16Ch(char x, char y, char N)
{
	unsigned char wm = 0;
	unsigned int adder = 32 * N;
	OLED_Set_Pos(x, y);
	for (wm = 0; wm < 16; wm++)
	{
		OLED_WrDat(pgm_read_byte(&F16x16[adder]));
		adder++;
	}
	OLED_Set_Pos(x, y + 1);
	for (wm = 0; wm < 16; wm++)
	{
		OLED_WrDat(pgm_read_byte(&F16x16[adder]));
		adder++;
	}
}

/*
//显示显示BMP图片128×64 起始点坐标xy x的范围0~127 y为页的范围0~7
void Draw_BMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

  if(y1%8==0) y=y1/8;
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {
	    	OLED_WrDat(BMP[j++]);
	    }
	}
}
*/
