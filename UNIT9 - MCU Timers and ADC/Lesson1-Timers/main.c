/*
 * TimerPWM.c
 *
 * Created: 23/03/03 03:42:38 AM
 * Author : VGA
 */ 

#define F_CPU 4000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

#define NULL (void*)(0)


void overover()
{
	//PORTB ^= 0xff;

	//Timer0_Stop();
	//Timer0_CTC(156, TIMER0_CTC_MODE_TOGGLE_OC0);

	//Timer0_Stop();
}

int main(void)
{
	timerConfig config = {
		.clock			   = TIMER0_PRESCALER_1024,
		.overflowInt	   = TIMER0_OV_INT_DE,
		.outputCmpMatchInt = TIMER0_OUTCMPMATCH_INT_EN,
		.ISR_OV			   = NULL,
		.ISR_CmpMatch	   = overover,
	};

	DDRB = 0Xff;

	sei();
	Timer0_Init(&config);
	//Timer0_Normal(255);
	DDRA = 0xff;
	PORTB = 0xff;

	//Timer0_CTC(156, TIMER0_PWM_FAST_MODE_CLEAR_OC0);
	Timer0_PWM_Fast(191, TIMER0_PWM_PHASECORRECT_MODE_SET_OC0);

	//Timer0_PWM_PhaseCorrect(191, TIMER0_PWM_PHASECORRECT_MODE_SET_OC0);
	PORTA = 0;
    /* Replace with your application code */
    while (1) 
    {
		//PORTA ^= 0xff;
		//Timer0_Normal(100);
		//delayT0();
		//_delay_us(100);
		//_delay_ms(100);
    }
}
