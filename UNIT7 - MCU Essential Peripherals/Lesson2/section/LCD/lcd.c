/*
 * lcd.c
 *
 * Created: 22/07/31 10:02:04 AM
 *  Author: Ziad
 */ 
#include <string.h>

#include "lcd.h"

#ifdef LCD_4BIT_MODE
#define LCD_DATASHIFT 4
#else
#define LCD_DATASHIFT 0
#endif


void LCD_KICK()
{
	LCDCR_PORT |= (1 << LCD_EN); // Set EN pin
	 _delay_us(1);
	 LCDCR_PORT &= ~(1 << LCD_EN); // Reset EN pin

}

void LCD_Clear_Screen(void)
{
	LCD_Write_Comand(LCD_CLEAR_SCREEN);

}
void LCD_Is_Busy(void)
{	
	
	 LCD_DDR &= ~(0xFF << LCD_DATASHIFT);
	 
	 LCDCR_PORT |= (1 << LCD_RW); // RW pin is read
	 LCDCR_PORT &= ~(1 << LCD_RS); // RS pin is write
	 LCD_KICK();
	 
	 LCD_DDR = 0xFF;
	 LCDCR_PORT &= ~(1 << LCD_RW);
}

void LCD_GotoXY(int line, int pos)
{
	
	if(line == 0)
	{
		if(pos > 15 || pos < 0)
			return;
		LCD_Write_Comand(LCD_BEGIN_AT_FIRST_RAW + pos);
	}
	else if(line == 1)
	{
		if(pos > 15 || pos < 0)
			return;
		LCD_Write_Comand(LCD_BEGIN_AT_SECOND_RAW + pos);
	}
}

void LCD_Init(void)
{
	_delay_ms(20);
	LCD_Is_Busy();
	LCDCR_DDR |= (1 << LCD_EN) | (1 << LCD_RW) | (1 << LCD_RS);
	LCDCR_PORT &= ~((1 << LCD_EN) | (1 << LCD_RW) | (1 << LCD_RS));
	LCD_DDR = 0xFF;
	LCD_Clear_Screen();
	_delay_ms(15);
#ifdef LCD_8BIT_MODE
	LCD_Write_Comand(LCD_FUNCTION_8BIT_2LINES);
#endif	
#ifdef LCD_4BIT_MODE
	LCD_Write_Comand(LCD_EN_4BIT);
	LCD_Write_Comand(LCD_FUNCTION_4BIT_2LINES);

#endif	
	
	LCD_Write_Comand(LCD_ENTRY_MODE);
	LCD_Write_Comand(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Write_Comand(LCD_DISP_ON_CURSOR_BLINK);

}



void LCD_Write_Comand(unsigned char command)
{
	LCD_Is_Busy();
	
#ifdef LCD_8BIT_MODE
	LCD_PORT = command;
	LCDCR_PORT &= ~((1 << LCD_RW) | (1 << LCD_RS));
	LCD_KICK();
#endif	
#ifdef LCD_4BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	
	LCDCR_PORT &= ~((1 << LCD_RW) | (1 << LCD_RS));
	LCD_KICK();
	 _delay_us(200);
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	
	LCDCR_PORT &= ~((1 << LCD_RW) | (1 << LCD_RS));
	LCD_KICK();
	_delay_ms(2);

#endif
}



void LCD_Write_Char(unsigned char data)
{
	

#ifdef LCD_8BIT_MODE
	LCD_Is_Busy();	
	LCD_PORT = data;
	LCDCR_PORT &= ~(1 << LCD_RW);
	LCDCR_PORT |= (1 << LCD_RS);
	LCD_KICK();
#endif	
#ifdef LCD_4BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);

	LCDCR_PORT &= ~(1 << LCD_RW);
	LCDCR_PORT |= (1 << LCD_RS);
	LCD_KICK();
	
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);

	LCDCR_PORT &= ~(1 << LCD_RW);
	LCDCR_PORT |= (1 << LCD_RS);
	LCD_KICK();
	_delay_us(100);


#endif
}

void LCD_Write_CustomChar()
{
	LCD_Write_Comand(64);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	LCD_Write_Char(0xff);
	
	LCD_Write_Comand(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Write_Char(0);
	
}


void LCD_Write_String(char* data)
{
	int count = 0;
	while(*data != 0)
	{
		if(count == 16)
		{
			LCD_GotoXY(1, 0);
		}
		else if (count == 32)
		{
			LCD_Clear_Screen();
			count = 0;
			LCD_GotoXY(0, 0);
		}
		
		LCD_Write_Char(*data);
		count++;
		data++;


	}
}


