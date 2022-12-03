/*
 * I2C.c
 *
 * Created: 22/12/03 01:46:10 AM
 *  Author: Ziad
 */ 

#include "I2C.h"

void I2C_master_init(uint8_t scl_clock, uint8_t prescaler)
{
	// clock
	TWBR = (uint8_t)(((F_CPU / scl_clock) - 16)  / 2);
	
	switch(prescaler)
	{
		case 0:
			TWSR = 0;
			break;
		case 4:
			TWSR = 1;
			break;
		case 16:
			TWSR = 2;
			break;
		case 64:
			TWSR  = 3;
			break;
	}

	
	
}

uint8_t I2C_master_start(uint8_t address, uint8_t control)
{
	// Send START condition
	TWCR = (1 << TWEN) |(1 << TWSTA) |(1 << TWINT) ;
	
	// Clear TWINT by writing it to one (It's set by the hardware after operation is done)
	while(!(TWCR & (1 << TWINT)));
	
	// if START has NOT been transmitted (TWSR with pre-scaler bits masked)
	if((TWSR & 0xF8) != I2C_MASTER_START_TRANSMITTED && ((TWSR & 0xF8) != I2C_MASTER_RSTART_TRANSMITTED))
		return TWSR;
	
	// Write SLAVE+CTR on TWDR
	TWDR = (address << 1) | control;
	
	// Clear TWINT TO start sending the address and Control
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	
	while(!(TWCR & (1 << TWINT)));
	
	uint8_t status = (TWSR & 0xF8);
	
	// If NACK or arbitration lost
	if(((control == I2C_MASTER_TRANSMITTER) && (status != 0x18)) || ((control == I2C_MASTER_RECEIVER) && (status != 0x40)))
	{
		return  (TWSR & 0xF8);
	}
	
	return 1;
}

uint8_t I2C_master_read(uint8_t *data, uint8_t ack)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);

	while(!(TWCR & (1 << TWINT)));
	
	*data = TWDR;
	
	//if data has not been received
	if((TWSR & 0xF8) != I2C_MASTER_DATA_RECEIVED_ACKED)
		return (TWSR & 0xF8);
	
	return 1;
}


uint8_t I2C_master_write(uint8_t data)
{
	// Writing data
	TWDR = data;
	
	// Clear TWINT to start sending data
	TWCR = (1<<TWINT) | (1<<TWEN);

	
	while(!(TWCR & (1 << TWINT)));
	
	// if NACK received
	if((TWSR & 0xF8) != I2C_MASTER_DATA_TRANSMITTED_ACKED)
		return (TWSR & 0xF8);
	
	return  1;
}

void I2C_master_stop()
{
	// Send STOP condition
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
	
}


void I2C_slave_init(uint8_t address, uint8_t generalcall)
{
	TWAR = (address << 1) | generalcall;
}

uint8_t I2C_slave_start()
{
	
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while(!(TWCR & (1 << TWINT)));
	
	// If not received its own address and acknowledged
	if((TWSR & 0xF8) == I2C_SLAVE_RECEIVER_ACKED)
		return I2C_SLAVE_RECEIVER;
	if((TWSR & 0xF8) == I2C_SLAVE_TRANSMITTER_ACKED)
		return I2C_SLAVE_TRANSMITTER;

	return 0;
}
uint8_t I2C_slave_read(uint8_t *data, uint8_t ack)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
	while(!(TWCR & (1 << TWINT)));
	
	*data = TWDR;
	
	//if data has not been received
	if((TWSR & 0xF8) != I2C_SLAVE_DATA_RECEIVED_ACKED)
		return (TWSR & 0xF8);
	
	return 1;
}

uint8_t I2C_slave_write(uint8_t data)
{
	// Writing data
	TWDR = data;
	
	// Clear TWINT to start sending data
	TWCR = (1<<TWINT) | (1<<TWEN) | (1 << TWEA);
	while(!(TWCR & (1 << TWINT)));
	
	// if NACK received
	if((TWSR & 0xF8) != I2C_SLAVE_DATA_TRANSMITTED_ACKED)
		return (TWSR & 0xF8);
	
	return  1;
}