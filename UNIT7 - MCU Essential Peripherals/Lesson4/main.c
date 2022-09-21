// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "lcd.h"
#include "keypad.h"
#include "stm32f103x6.h"
#include "Stm32_F103C6_EXTI.h"
#include "Stm32_F103C6_GPIO.h"

void clock_init()
{
	// Using internal 8 MHz RC oscillator
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

}

void GPIO_init()
{
	GPIO_PinConfig_t pinCfg;



	// Initializing GPIOA
	// PIN 1 is input - open drain
	pinCfg.GPIO_PinNumber = GPIO_PIN_1;
	pinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinCfg);

	// PIN 13 is input - open drain
	pinCfg.GPIO_PinNumber = GPIO_PIN_13;
	pinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinCfg);
	// Initializing GPIOB

	// PIN 1 is output - push-pull
	pinCfg.GPIO_PinNumber = GPIO_PIN_1;
	pinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	// PIN 13 is output - push-pull
	pinCfg.GPIO_PinNumber = GPIO_PIN_13;
	pinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);


}

void delay(int a)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < 255; j++);
	}
}

void interrupt_callback()
{
	LCD_Write_String("IRQ, EXTI9 happened --__");

}
int main(void)
{

	clock_init();
	LCD_Init();
	KPAD_Init();

	EXTI_PinConfig_t  EXTI_Config;
	EXTI_Config.EXTI_Pin = EXTI9PB9;
	EXTI_Config.IRQ_Enable = EXTI_IRQ_Enable;
	EXTI_Config.Trigger_Case = EXTI_FT;
	EXTI_Config.P_IRQ_CallBack = interrupt_callback;

	MCAL_EXTI_GPIO_Init(&EXTI_Config);

	delay(50);
	//LCD_Write_String("Hello, worldHappy to see you today, thank youlol");
	while(1)
	{
		char c = KPAD_Get_Char();
		if(c == 'c')
			LCD_Clear_Screen();
		else if(c != 0)
			LCD_Write_Char(c);
		delay(1);
	}

}
