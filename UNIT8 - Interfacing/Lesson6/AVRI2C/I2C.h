/*
 * I2C.h
 *
 * Created: 22/12/03 01:45:56 AM
 *  Author: ziad
 */ 


#ifndef I2C_H_
#define I2C_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>

#define I2C_MASTER_RECEIVER					(uint8_t)(0x01) // I2C master works as receiver
#define I2C_MASTER_TRANSMITTER				(uint8_t)(0x00) // I2C master works as transmitter

#define I2C_MASTER_START_TRANSMITTED		(uint8_t)(0x08) // A START condition has been transmitted
#define I2C_MASTER_RSTART_TRANSMITTED		(uint8_t)(0x10) // A Repeated START condition has been transmitted

#define I2C_MASTER_DATA_RECEIVED_ACKED		(uint8_t)(0x50)	// Data byte has been received, ACK has been returned
#define I2C_MASTER_DATA_TRANSMITTED_ACKED	(uint8_t)(0x28) // Data byte has been transmitted, ACK has been received

#define I2C_SLAVE_GCSET						(uint8_t)(0x01) // The slave will respond to the general call address ($00)
#define I2C_SLAVE_GCRESET					(uint8_t)(0x00) // The slave will ignore the general call address ($00)

#define I2C_SLAVE_TRANSMITTER				(uint8_t)(0x02) // I2C slave works as transmitter
#define I2C_SLAVE_RECEIVER					(uint8_t)(0x01) // I2C slave works as receiver

#define I2C_SLAVE_RECEIVER_ACKED			(uint8_t)(0x60) // Own SLA+W has been received, ACK has been returned
#define I2C_SLAVE_TRANSMITTER_ACKED			(uint8_t)(0xA8) // Own SLA+R has been received, ACK has been returned

#define I2C_SLAVE_DATA_RECEIVED_ACKED		(uint8_t)(0x80) // Previously addressed with own SLA+W; data has been received; ACK has been returned
#define I2C_SLAVE_DATA_TRANSMITTED_ACKED	(uint8_t)(0xB8) // Data byte in TWDR has been transmitted; ACK has been received


/** @brief This function initializes the master clock
 *  @param scl_clock The required scl_clock
 *  @param prescaler The required prescaler
 *  @return None
 */
void I2C_master_init(uint8_t scl_clock, uint8_t prescaler);


/** @brief This function sends the START condition to the required address
 *  @param address The address you want to send to
 *  @param control the data flow (I2C_MASTER_RECEIVER or I2C_MASTER_TRANSMITTER)
 *  @return 1 on success. On failure, it returns the corresponding status register code
 */
uint8_t I2C_master_start(uint8_t address, uint8_t control);


/** @brief This function starts read operation
 *  @param *data Output pointer to store the incoming data
 *  @param ack (1:send ACK, 0: send NACK)
 *  @return 1 on success. On failure, it returns the corresponding status register code
 */
uint8_t I2C_master_read(uint8_t *data, uint8_t ack);


/** @brief This function starts write operation
 *  @param data the data to be sent
 *  @return 1 on success. On failure, it returns the corresponding status register code
 */
uint8_t I2C_master_write(uint8_t data);


/** @brief This function sends STOP condition
 *  @return NONE
 */
void I2C_master_stop();


/** @brief This function initializes the slave address and if will respond to general call
 *  @param address the slave address
 *  @param generalcall (I2C_SLAVE_GCSET: respond to general call, I2C_SLAVE_GCRESET: ignore general call)
 *  @return None
 */
void I2C_slave_init(uint8_t address, uint8_t generalcall);


/** @brief This function polls until it finds its own address
 *  @return (I2C_SLAVE_RECEIVER, I2C_SLAVE_TRANSMITTER)
 */
uint8_t I2C_slave_start();


/** @brief This function starts read operation
 *  @param *data Output pointer to store the incoming data
 *  @param ack (1:send ACK, 0: send NACK)
 *  @return 1 on success. On failure, it returns the corresponding status register code
 */
uint8_t I2C_slave_read(uint8_t *data, uint8_t ack);

/** @brief This function starts write operation
 *  @param data the data to be sent
 *  @return 1 on success. On failure, it returns the corresponding status register code
 */
uint8_t I2C_slave_write(uint8_t data);

#endif /* I2C_H_ */