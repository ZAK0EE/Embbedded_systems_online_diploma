/*
 * SPI_Transmitter.c
 *
 * Created: 22/08/28 01:16:26 PM
 * Author : Ziad
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>


void SPI_Master_Init()
{
	SPCR |= (1 << MSTR);
	SPCR &= ~(0b11 << SPR0);
	// Enable SPI
	SPCR |= (1 << SPE);
}

void SPI_Slave_Init()
{
	SPCR &= ~(0b11 << SPR0);
	// Enable SPI
	SPCR |= (1 << SPE);
}
void SPI_Transmit(uint8_t data)
{
	SPDR = data;
	while(!((SPSR >> SPIF) & 1));	
}

uint8_t SPI_Receive()
{
	
	while(!((SPSR >> SPIF) & 1));
	return SPDR;
}

uint8_t SPI_Transfer(uint8_t data)
{
	SPDR = data;
	while(!((SPSR >> SPIF) & 1));
	return SPDR;
}

//TRANSMITTER
int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	PORTB = 0x0;
	DDRA = 0xff;
	SPI_Init();
	
	// Lower the SS
	PORTB &= ~(1 << 4);
	PORTB |= (1 << 4);
	
	uint8_t data = 0;
// Initial poweruup
	PORTB &= ~(1 << 4);
	SPI_Transfer(0X0C);
	SPI_Transfer(0x01);
	PORTB |= (1 << 4);
// Decode
	PORTB &= ~(1 << 4);
	SPI_Transfer(0x09);
	SPI_Transfer(0xFF);
	PORTB |= (1 << 4);
// Scan code
	PORTB &= ~(1 << 4);
	SPI_Transfer(0x0B);
	SPI_Transfer(0xF7);
	PORTB |= (1 << 4);
// Intensity
	PORTB &= ~(1 << 4);
	SPI_Transfer(0X0A);
	SPI_Transfer(0x0F);
	PORTB |= (1 << 4);
// Digit
	// Address
	PORTB &= ~(1 << 4);
	SPI_Transfer(0x04);
	// Data
	SPI_Transfer(0x09);
	PORTB |= (1 << 4);
    while (1) 
    {

		_delay_ms(200);
    }
}

