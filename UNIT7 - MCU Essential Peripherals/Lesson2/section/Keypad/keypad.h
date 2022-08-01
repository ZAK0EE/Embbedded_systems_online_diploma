/*
 * keypad.h
 *
 * Created: 22/07/31 05:29:00 PM
 *  Author: Ziad
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include <avr/io.h>

#define KPAD_PORT PORTD
#define KPAD_DDR DDRD
#define KPAD_PIN PIND

// Keypad Rows
#define KPAD_R0 0
#define KPAD_R1 1
#define KPAD_R2 2
#define KPAD_R3 3

// Keypad Columns
#define KPAD_C0 4
#define KPAD_C1 5
#define KPAD_C2 6
#define KPAD_C3 7

void KPAD_Init();

char KPAD_Get_Char();
#endif /* KEYPAD_H_ */