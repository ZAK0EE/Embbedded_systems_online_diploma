/*
 * External Interrupt.c
 *
 * Created: 13/04/2022 01:27:38 
 * Author : Ziad Gamalelden
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)
{
    PORTD |= (1 << PD5);
    _delay_ms(1000);
    PORTD &= ~(1 << PD5);
}

ISR(INT1_vect)
{
    PORTD |= (1 << PD6);
    _delay_ms(1000);
    PORTD &= ~(1 << PD6); 
}

ISR(INT2_vect)
{
    PORTD |= (1 << PD7);
    _delay_ms(1000);
    PORTD &= ~(1 << PD7);    
}

void GPIO_init()
{
    
    // Pins 5, 6, 7 as output for LEDS
    DDRD |= (1 << PD5) | (1 << PD6) | (1 << PD7);
    
}    

void EXTI_init()
{

    // Any logical change on INT0 generates an interrupt request.
    MCUCR |= (0b01 << 0); // ISC01, ISC00 
    
    // The rising edge of INT1 generates an interrupt request.
    MCUCR |= (0b11 << 2); // ISC11, ISC10
    
    // If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
    MCUCSR &= ~(1 << ISC2);
    
    //The External Interrupt x  is activated by the external pin INTx if:
    //1- the SREG I-bit is set
    //2- the corresponding interrupt mask in the GICR are set.
    
    // Global Interrupt Enable (SREG I-bit)
    SREG |= (1 << 7);
    // Setting interrupt masks in GICR
    GICR |= (1 << INT0) | (1 << INT1) | (1 << INT2);
}

int main(void)
{
    GPIO_init();
    EXTI_init();

    /* Replace with your application code */
    while (1) 
    {

    }
}

