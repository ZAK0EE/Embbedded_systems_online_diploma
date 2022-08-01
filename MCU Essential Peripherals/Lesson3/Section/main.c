// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio.h"
#include "Stm32_F103C6_EXTI.h"
#include "lcd.h"
#include "keypad.h"

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
int main(void)
{

	clock_init();
	LCD_Init();
	KPAD_Init();
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
