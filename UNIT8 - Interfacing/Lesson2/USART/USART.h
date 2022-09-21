/*
 * USART.h
 *
 * Created: 22/08/08 05:49:53 PM
 *  Author: Ziad
 */ 


#ifndef USART_H_
#define USART_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <stdint.h>

void USART_Init(void);
void USART_Send(uint8_t data);
uint8_t USART_Receive(void);



#endif /* USART_H_ */