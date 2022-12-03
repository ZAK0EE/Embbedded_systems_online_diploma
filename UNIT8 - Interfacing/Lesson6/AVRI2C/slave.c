/*
 * I2C_Slave.c
 *
 * Created: 22/11/25 10:20:10 PM
 * Author : VGA
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
	DDRA = 0xFF;
	DDRD = 0XFF;
	
	uint8_t data = 0x25;
	uint8_t address = 32;
	uint8_t ack = 1;

	I2C_slave_init(address, I2C_SLAVE_GCSET); 
    while (1) 
    {
		uint8_t startStatus = I2C_slave_start();
		if(startStatus == I2C_SLAVE_RECEIVER)
		{
			if(I2C_slave_read(&data, ack) == 1)
				PORTA = data;							
		}
		else if (startStatus == I2C_SLAVE_TRANSMITTER)
		{
			if((I2C_slave_write(data)) == 1)
				PORTD = 0xFF;
		}
		else
		{
				PORTB ^= 0xFF;
				_delay_ms(100);
		}
				
	}
}

