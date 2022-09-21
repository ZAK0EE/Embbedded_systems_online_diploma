/*
 * LCD_INTERFACE_W_KEYPAD.c
 *
 * Created: 22/07/31 10:00:52 AM
 * Author : Ziad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <stdint.h>
#include "USART/usart.h"
#include "LCD/lcd.h"
#include "Keypad/keypad.h"
int main(void)
{
    /* Replace with your application code */
	// Turn Led on
	DDRD |= 0x1;
	PORTA |= 0x1;
	
	LCD_Init();
	//KPAD_Init();
	//LCD_Write_CustomChar();
	//LCD_Write_String("Hello, world");
	USART_Init();
	//USART_Send('H');
    while (1) 
    {
		uint8_t x  = USART_Receive();
		USART_Send(x);
		LCD_Write_Char(x);
    }
}

