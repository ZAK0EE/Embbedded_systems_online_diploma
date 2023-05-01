/*
 * ADC.h
 *
 * Created: 23/05/01 07:13:24 PM
 *  Author: Ziad
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <inttypes.h>

typedef enum
{
    ADC_REF_AREF                            = 0b00 << REFS0,
    ADC_REF_AVCC                            = 0b01 << REFS0,
    ADC_REF_INTERNAL2_56                    = 0b11 << REFS0,
}ADC_voltReference_enum;

typedef enum
{
    ADC_DATAADJUSTMENT_LEFT                  = 0b1 << ADLAR,
    ADC_DATAADJUSTMENT_RIGHT                 = 0b0 << ADLAR,
}ADC_dataAdjustment_enum;

typedef enum
{
    ADC_INT_ENABLED                         = 0b1 << ADIE,
    ADC_INT_DISABLED                        = 0b0 << ADIE,
}ADC_interruptEn_enum;

typedef enum
{
    ADC_AUTOTRIGGER_ENABLED                 = 0b1 << ADATE,
    ADC_AUTOTRIGGER_DISABLED                = 0b0 << ADATE,
}ADC_autoTriggerEn_enum;


typedef enum
{
    ADC_AUTOTRIGGER_FREERUNNING             = 0b000 << ADTS0,
    ADC_AUTOTRIGGER_ANALOGCOMPARATOR        = 0b001 << ADTS0,
    ADC_AUTOTRIGGER_EXTERNALINTREQ0         = 0b010 << ADTS0,
    ADC_AUTOTRIGGER_TIMER0CMPMATCH          = 0b011 << ADTS0,
    ADC_AUTOTRIGGER_TIMER0OV                = 0b100 << ADTS0,
    ADC_AUTOTRIGGER_TIMER0CMPMATCHB         = 0b101 << ADTS0,
    ADC_AUTOTRIGGER_TIMER1OV                = 0b110 << ADTS0,
    ADC_AUTOTRIGGER_TIMER1CAPEVENT          = 0b111 << ADTS0,
}ADC_autoTriggerSource_enum;

typedef enum
{
    ADC_PRESCALER_2                         = 0b000 << ADPS0,
    ADC_PRESCALER_4                         = 0b010 << ADPS0,
    ADC_PRESCALER_8                         = 0b011 << ADPS0,
    ADC_PRESCALER_16                        = 0b100 << ADPS0,
    ADC_PRESCALER_32                        = 0b101 << ADPS0,
    ADC_PRESCALER_64                        = 0b110 << ADPS0,
    ADC_PRESCALER_128                       = 0b111 << ADPS0,
    
}ADC_prescaler_enum;


/* To be extended for differential channels */
typedef enum
{
    ADC_CHANNEL_0                           = 0b0000 << MUX0,
    ADC_CHANNEL_1                           = 0b0010 << MUX0,
    ADC_CHANNEL_2                           = 0b0011 << MUX0,
    ADC_CHANNEL_3                           = 0b0100 << MUX0,
    ADC_CHANNEL_4                           = 0b0101 << MUX0,
    ADC_CHANNEL_5                           = 0b0110 << MUX0,
    ADC_CHANNEL_6                           = 0b0111 << MUX0,
    ADC_CHANNEL_7                           = 0b0111 << MUX0,

}ADC_channel_enum;


typedef struct
{
    uint8_t			voltReference;				/* @ref ADC_voltReference_enum */
    uint8_t			dataAdjustment;	            /* @ref ADC_dataAdjustment_enum */
    uint8_t			interruptEn;		        /* @ref ADC_interruptEn_enum */
    uint8_t         autoTriggerEn;              /* @ref ADC_autoTriggerEn_enum */
    uint8_t         autoTriggerSource;          /* @ref ADC_autoTriggerSource_enum */
    uint8_t         prescaler;                  /* @ref ADC_prescaler_enum */
        
    void			(*ISR_ConvCompleted)();
}ADC_Config_type;

void ADC_Init(ADC_Config_type* config);

uint16_t ADC_StartConversion(uint8_t channel);

void ADC_DeInit();







#endif /* ADC_H_ */