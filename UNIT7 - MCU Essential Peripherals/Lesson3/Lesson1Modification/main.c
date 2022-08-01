// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "../Stm32_F103C6_Drivers/inc/stm32f103x6.h"
#include "../Stm32_F103C6_Drivers/inc/Stm32_F103C6_gpio.h"





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
	GPIO_init();




	int prevValue = 1;
	int currentValue = 1;
	while(1)
	{
		//currentValue = (GPIOA_IDR & (1 << 1)) >> 1;
		currentValue = MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		// Single press
		if(prevValue != currentValue)
		{
			if(currentValue == 0)
				MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			prevValue = currentValue;
		}

/*
		// Old method for single press
		if(currentValue == 0)
		{
			GPIOB_ODR ^= (1 << 1);
			while((GPIOA_IDR & (1 << 1)) == 0);
		}
*/

		// Multi press
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);

		}
		delay(1);
	}

}
