/*
 * GccApplication1.c
 *
 * Created: 22/09/24 02:30:49 PM
 * Author : Ziad
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

#include "I2C.h"

int main(void)
{

	DDRB = 0xFF; // Port B output
	
	int address = 32;
	uint8_t data = 0x50;
	uint8_t scl_clock = 0x48;
	uint8_t prescaler = 0;
	
	I2C_master_init(scl_clock, prescaler);
	I2C_master_start(address, I2C_MASTER_TRANSMITTER);
	I2C_master_write(data);

	I2C_master_start(address, I2C_MASTER_RECEIVER); // Repeated start
	if(I2C_master_read(&data, 1) == 1)
	{
		PORTB = data;
	}

	I2C_master_stop();
	
    while (1) 
    {		

    }
}

