/*
 * timer.c
 *
 * Created: 23/03/08 10:35:42 PM
 *  Author: Ziad
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h> // For NULL
#include "timer.h"

timerConfig  Timer0_config;

ISR(TIMER0_OVF_vect)
{
	if(Timer0_config.ISR_OV != NULL)
	{
		Timer0_config.ISR_OV();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(Timer0_config.ISR_CmpMatch != NULL)
	{
		Timer0_config.ISR_CmpMatch();
	}
}

void Timer0_Init(timerConfig *config)
{
	Timer0_config = *config;
		
	TIMSK = (TIMSK & 0b00) | config->overflowInt | config->outputCmpMatchInt;
}


void Timer0_Normal(uint8_t ticks)
{
	TCCR0 = 0;
	TCNT0 = 256 - ticks;
	
	Timer0_Start();
	
	if(Timer0_config.overflowInt == TIMER0_OV_INT_EN)
	{
		return;
	}
	
	while(((TIFR >> TOV0) & 1) != 1);
	
	Timer0_Stop();
	
	TIFR |= (1<<TOV0);

}

void Timer0_CTC(uint8_t ticks, uint8_t mode)
{
	TCCR0 = 0;
	// CTC mode
	TCCR0 &= ~(1 << WGM00);
	TCCR0 |=  (1 << WGM01);
	
	// Choose required mode for CTC
	TCCR0 &= ~(0b11 << COM00);
	TCCR0 |= mode;
	
	OCR0 = ticks;
	TCNT0 = 0;
	
	Timer0_Start();
	
	if(Timer0_config.outputCmpMatchInt == TIMER0_OUTCMPMATCH_INT_EN)
	{
		return;
	}
	
	while(((TIFR >> OCF0) & 1) != 1);
	
	Timer0_Stop();	
	TIFR |= (1 << OCF0);
	
}

void Timer0_PWM_Fast(uint8_t ticks, uint8_t mode)
{
	TCCR0 = 0;
	// PWM_Fast mode
	TCCR0 |= (1 << WGM00);
	TCCR0 |= (1 << WGM01);
	
	// Choose required mode for PWM_Fast
	TCCR0 &= ~(0b11 << COM00);
	TCCR0 |= mode;

	TCNT0 = 0;
	OCR0 = ticks;
	
	Timer0_Start();
}

void Timer0_PWM_PhaseCorrect(uint16_t ticks, uint8_t mode)
{
	// PWM_PhaseCorrect mode
	TCCR0 |=  (1 << WGM00);
	TCCR0 &= ~(1 << WGM01);
	
	// Choose required mode for PWM_PhaseCorrect
	TCCR0 &= ~(0b11 << COM00);
	TCCR0 |= mode;	
	
	OCR0 = ticks;
	
	Timer0_Start();
}

void Timer0_Start(void)
{
	TCCR0 = (TCCR0 & ~(0b111)) | Timer0_config.clock;
}

void Timer0_Stop(void)
{
	TCCR0 &= ~(0b111);
}

uint8_t		Timer0_GetCounter(void){return TCNT0;}
uint8_t		Timer0_GetCompare(void){return OCR0;}
	
void		Timer0_SetCounter (uint8_t ticks){TCNT0 = ticks;}
void		Timer0_SetCompare (uint8_t ticks){OCR0 = ticks;}
	
void		Timer0_ResetPrescaler(void){SFIOR |= (1 << PSR10);}
void		Timer0_ForceMatch(void){TCCR0 |= (1 << FOC0);}