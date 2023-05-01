/*
 * ADC.c
 *
 * Created: 23/05/01 07:13:14 PM
 *  Author: Ziad
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>

#include "ADC.h"

ADC_Config_type myConfig;


ISR(ADC_vect)
{
    if(myConfig.ISR_ConvCompleted != NULL)
    {
        //myConfig.ISR_ConvCompleted();
    }
}


void ADC_Init(ADC_Config_type* config)
{
    myConfig = *config;
    
    ADMUX  = 0;
    ADMUX  |= myConfig.voltReference | myConfig.dataAdjustment;
    
    ADCSRA = 0;
    ADCSRA |= myConfig.interruptEn | myConfig.prescaler | myConfig.autoTriggerEn;
    
    if(myConfig.autoTriggerEn == ADC_AUTOTRIGGER_ENABLED)
    {
        SFIOR |= myConfig.autoTriggerSource;
    }
    
    ADCSRA |= (1 << ADEN);
}

uint16_t ADC_StartConversion(uint8_t channel)
{
    ADMUX  |= channel;
    ADCSRA |= (1 << ADSC);
    
    if(myConfig.interruptEn == ADC_INT_ENABLED)
    {
        return 0;
    }
    
    while(!((ADCSRA >> ADIF) & 1));
    
    return ADC;
}

void ADC_DeInit()
{
    ADMUX = 0;
    ADCSRA = 0;
    SFIOR &= ~(0b111 << ADTS0);
}