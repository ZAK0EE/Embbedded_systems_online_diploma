/*
 * LCD_INTERFACE_W_KEYPAD.c
 *
 * Created: 22/07/31 10:00:52 AM
 * Author : Ziad
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include "LCD/lcd.h"
#include "Keypad/keypad.h"
int main(void)
{
    /* Replace with your application code */
	// Turn Led on
	DDRD |= 0x1;
	PORTA |= 0x1;
	
	LCD_Init();
	KPAD_Init();
	//LCD_Write_CustomChar();
	//LCD_Write_String("gOOD BYE");
    while (1) 
    {
		char c = KPAD_Get_Char();
		if(c == 'c')
			LCD_Clear_Screen();
		else if(c != 0)
			LCD_Write_Char(c);
		_delay_ms(50);
    }
}

