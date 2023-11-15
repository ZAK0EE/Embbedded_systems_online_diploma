// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "lcd.h"
#include "keypad.h"
#include "stm32f103x6.h"
#include "Stm32_F103C6_EXTI.h"
#include "Stm32_F103C6_GPIO.h"

// Implement cpu exception functions, so the cpu can halt in them
void HardFault_Handler()
{
	//main();
}

void BusFault_Handler()
{

}

void UsageFault_Handler()
{

}



void clock_init()
{
	// Using internal 8 MHz RC oscillator
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

}



void delay(int a)
{
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < 255; j++);
	}
}

int x = 98;
int y = 99;


enum CPUAccessLevel
{
	PRIVILAGED,
	UNPRIVILAGED
};
void CPU_SwitchAccess(enum CPUAccessLevel level)
{
	switch(level)
	{
	case PRIVILAGED:
		__asm(
			"mrs r3, CONTROL \n\t"
			"lsr r3, r3, #0x1 \n\t"
			"lsl r3, r3, #0x1 \n\t"
			"msr CONTROL, r3 \n\t"

		);
		break;
	case UNPRIVILAGED:
		__asm(
			"mrs r3, CONTROL \n\t"
			"orr r3, r3, #0x1 \n\t"
			"msr CONTROL, r3 \n\t"
		);
		break;
	}
}



void SVC_Handler()
{
	CPU_SwitchAccess(PRIVILAGED);

}

void interrupt_callback()
{
	LCD_Write_String("IRQ, EXTI9 happened --__");
	//int control = -1;
	//int IPSR = -1;


/*
	__asm(
			"MRS %[out0], CONTROL\n"
			"MRS %[out1], IPSR\n"
			:	[out0] "=r" (control), //Output parameters
				[out1] "=r" (IPSR)
				:   //Input parameters

	);
*/
}
int main(void)
{

	clock_init();
	LCD_Init();

	CPU_SwitchAccess(UNPRIVILAGED);

	EXTI_PinConfig_t  EXTI_Config;
	EXTI_Config.EXTI_Pin = EXTI9PB9;
	EXTI_Config.IRQ_Enable = EXTI_IRQ_Enable;
	EXTI_Config.Trigger_Case = EXTI_FT;
	EXTI_Config.P_IRQ_CallBack = interrupt_callback;

	MCAL_EXTI_GPIO_Init(&EXTI_Config);

	//CPU_SwitchAccess(UNPRIVILAGED);
	//CPU_SwitchAccess(PRIVILAGED);


	delay(50);
	//LCD_Write_String("Hello, worldHappy to see you today, thank youlol");
	while(1)
	{

		delay(1);
	}

}
