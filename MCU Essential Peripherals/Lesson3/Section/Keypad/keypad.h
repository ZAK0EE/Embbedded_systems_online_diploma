/*
 * keypad.h
 *
 * Created: 22/07/31 05:29:00 PM
 *  Author: Ziad
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

//#define F_CPU 1000000UL
#include "Stm32_F103C6_gpio.h"
//#include <avr/io.h>

#define KPAD_PORT GPIOB
//#define KPAD_DDR DDRD
//#define KPAD_PIN PIND

// Keypad Rows
#define KPAD_R0 GPIO_PIN_3
#define KPAD_R1 GPIO_PIN_4
#define KPAD_R2 GPIO_PIN_5
#define KPAD_R3 GPIO_PIN_6

// Keypad Columns
#define KPAD_C0 GPIO_PIN_12
#define KPAD_C1 GPIO_PIN_13
#define KPAD_C2 GPIO_PIN_14
#define KPAD_C3 GPIO_PIN_15

void KPAD_Init();

char KPAD_Get_Char();
#endif /* KEYPAD_H_ */
