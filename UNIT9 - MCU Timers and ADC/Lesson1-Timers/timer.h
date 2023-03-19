/*
 * timer.h
 *
 * Created: 23/03/08 10:36:04 PM
 *  Author: Ziad
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <inttypes.h>

typedef enum
{
	TIMER0_PRESCALER_NONE = 0b0001,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
	TIMER0_EXT_FALLING,
	TIMER0_EXT_RISING,
	
}ClockType_t;

typedef enum
{
	TIMER0_OUTCMPMATCH_INT_EN = 0b10,
	TIMER0_OUTCMPMATCH_INT_DE = 0b00,
}outputCmpMatchIntType_t;

typedef enum
{
	TIMER0_OV_INT_EN = 1,
	TIMER0_OV_INT_DE = 0,
}overflowIntType_t;

typedef enum
{
	TIMER0_CTC_MODE_NORMAL     = (0b00 << COM00),
	TIMER0_CTC_MODE_TOGGLE_OC0 = (0b01 << COM00),
	TIMER0_CTC_MODE_CLEAR_OC0  = (0b10 << COM00),
	TIMER0_CTC_MODE_SET_OC0    = (0b11 << COM00),
}CTC_modeType_t;

typedef enum
{
	TIMER0_PWM_FAST_MODE_NORMAL     = (0b00 << COM00),
	TIMER0_PWM_FAST_MODE_CLEAR_OC0  = (0b10 << COM00),
	TIMER0_PWM_FAST_MODE_SET_OC0    = (0b11 << COM00),
}PWM_Fast_modeType_t;              

typedef enum
{
	TIMER0_PWM_PHASECORRECT_MODE_NORMAL    = (0b00 << COM00),
	TIMER0_PWM_PHASECORRECT_MODE_CLEAR_OC0 = (0b10 << COM00),
	TIMER0_PWM_PHASECORRECT_MODE_SET_OC0   = (0b11 << COM00),
}PWM_PhaseCorrect_modeType_t;

typedef struct  
{
	uint8_t			clock;				/* @ref ClockType_t */
	uint8_t			outputCmpMatchInt;	/* @ref outputCmpMatchIntType_t */
	uint8_t			overflowInt;		/* @ref overflowIntType_t */
	void			(*ISR_OV)();
	void			(*ISR_CmpMatch)();
}timerConfig;

void Timer0_Init(timerConfig *config);

void Timer0_Normal(uint8_t ticks);

void Timer0_CTC(uint8_t ticks, uint8_t mode);

void Timer0_PWM_Fast(uint8_t ticks, uint8_t mode);

void Timer0_PWM_PhaseCorrect(uint16_t ticks, uint8_t mode);

void Timer0_Start(void);
void Timer0_Stop(void);

uint8_t		Timer0_GetCounter(void);
uint8_t		Timer0_GetCompare(void);
void		Timer0_SetCounter (uint8_t counter);
void		Timer0_SetCompare (uint8_t compare);
void		Timer0_ResetPrescaler(void);
void		Timer0_ForceMatch(void);
#endif /* TIMER_H_ */