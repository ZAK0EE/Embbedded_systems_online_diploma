/*
 * GDSC_Project.c
 *
 * Created: 23/02/13 10:27:33 PM
 * Author : VGA
 */ 
#define F_CPU 8000000ul
#define FOSC 8000000ul// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "ADC.h"
char *const gPassword = "ziad";

// ***********************************************UART***********************************************

void UART_INIT()
{
	UBRRL = (uint8_t)(MYUBRR) ;    //send the low  8 bits of the UBRR
	UBRRH = (uint8_t)(MYUBRR>>8);//send the high 4 bits of the UBRR
	UCSRB |=((1<<4)|(1<<3));     //Enable transmit and enable RXENn TXENn
	UCSRC |=((1<<2)|(1<<1));     //Frame with 8 bit data , 1 stop bit, no parity UCSZn1 UCSZn0 , Asynchornous mode
}


void UART_Transmit(uint8_t data)
{  while( !(UCSRA & (1<<5)) ) ;// wait until the buffer is empty UDREn
	UDR=data;
}
uint8_t UART_Read()
{ 
	while( !(UCSRA & (1<<7)) ) ;//wait until the receiving complete RXCn
	return UDR;
}

void UART_Read_string(uint8_t *buffer, uint32_t size)
{
	int idx = 0;
	uint8_t received = 0;
	do
	{
		received = UART_Read();
		buffer[idx++] = received;
	}
	while(idx < size && (received != '\r'));
	
	buffer[idx - 1] = 0;
}

void UART_Transmit_string (char * str)
{
	unsigned char i =0 ;
	while(str[i]!=0)
	{UART_Transmit(str[i]) ; i++;}
}


// // ***********************************************MENU***********************************************

int Check_Password(void)
{
	char UART_buffer[100];
	
	UART_Transmit_string("Password: ");
	UART_Read_string(UART_buffer, 100);
	return (strcmp(UART_buffer, gPassword) == 0);
}

void Show_Temperature(void)
{
	float celsius=(ADC_StartConversion(ADC_CHANNEL_0)*4.88);	/* Read ADC channel 0 */
	celsius = (celsius/10.00);
	
	char buffer[30];	
	sprintf(buffer, "Temperature is: %d\r", (int)celsius);
	
	UART_Transmit_string(buffer);
}

int Show_Menu(void)
{
	
	UART_Transmit_string("*********Menu*********\r");
	UART_Transmit_string("0- Logout\r");
	UART_Transmit_string("1- Show temperature\r");
	UART_Transmit_string("2- Toggle red led\r");
	UART_Transmit_string("3- Toggle yellow led\r");
	UART_Transmit_string("4- Toggle green led\r");
	UART_Transmit_string("Please choose service: ");
	
	char UART_buffer[100];	
	UART_Read_string(UART_buffer, 100);
	int choice = UART_buffer[0] - '0';
	
	return choice;

}


int main (void)
{    

	
	
	UART_INIT();
    DDRA = 0x00;	        /* Make ADC port as input */

    ADC_Config_type config =
    {
        .voltReference  = ADC_REF_AVCC,
        .dataAdjustment = ADC_DATAADJUSTMENT_RIGHT,
        .interruptEn    = ADC_INT_DISABLED,
        .autoTriggerEn  = ADC_AUTOTRIGGER_DISABLED,
        .prescaler      = ADC_PRESCALER_128,
    };
    ADC_Init(&config);
    
    DDRB = 0xFF; //output
	int choice = 0;
	
	while(1){
		
		while(Check_Password() != 1);
		
		do 
		{
	
			choice = Show_Menu();
			switch(choice)
			{
				
			case 1:
				Show_Temperature();
				break;	
			case 2:
				PORTB ^= (1 << 0);
				break;
			case 3:
				PORTB ^= (1 << 1);
				break;	
			case 4:
				PORTB ^= (1 << 2);
				break;			
				
			}
			
			UART_Transmit('\r');
			
		} while (choice != 0);

	}
}


