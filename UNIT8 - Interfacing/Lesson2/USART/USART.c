/*
 * USART.c
 *
 * Created: 22/08/08 05:49:36 PM
 *  Author: Ziad
 */ 

#include "usart.h"

void USART_Init(void)
{
	// Baud Rate - 9600
	UBRRL = 51;
	UCSRA &= ~(1 << U2X); // Normal mode
	
	// Frame
	UCSRC &= ~(1 << UMSEL); // Asynchronous
	UCSRC &= ~(0b11 << UPM0); // Parity disableda1
	
	UCSRC &= ~(0b111 << UCSZ0); // Clear character size bits
	UCSRC |= (0b011 << UCSZ0); // Character size 8bit
	
	// Enable peripheral
	UCSRB |= (1 << TXEN) | (1 << RXEN);
}

void USART_Send(uint8_t data)
{
	while( !((UCSRA >> UDRE) & 1));
	
	UDR = data;
	
}
uint8_t USART_Receive(void)
{
	while( !((UCSRA >> RXC) & 1));
	return UDR;
}