// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include "lcd.h"
#include "keypad.h"
#include "stm32f103x6.h"
#include "Stm32_F103C6_EXTI.h"
#include "Stm32_F103C6_GPIO.h"

extern int _estack;

#define TaskA_Stack_Size 100 // 100 Bytes
#define TaskB_Stack_Size 100 // 100 Bytes

#define OS_SET_PSP(address) __asm volatile(				  \
								"MOV R0, %[add]\n\r"  \
								"MSR PSP, R0\n\r"		  \
								:						  \
								: [add] "r" (address) \
							) 							  \

#define OS_SWITCH_SP_TO_PSP()  __asm volatile(\
								"MRS R0, CONTROL \n\r"\
								"MOV R1, #0x2\n\r"\
								"ORR R0, R0, R1\n\r"\
								"MSR CONTROL, R0"\
							)

#define OS_SWITCH_SP_TO_MSP()  __asm volatile(\
								"MRS R0, CONTROL \n\r"\
								"MOV R1, #0x5\n\r"\
								"AND R0, R0, R1\n\r"\
								"MSR CONTROL, R0"\
							)

#define OS_GENERATE_EXCEPTION() __asm volatile("SVC #0x03")

// Main stack
unsigned int _S_MSP = (unsigned int)&_estack;
unsigned int _E_MSP;

// Process Stack (TASKA)
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;

// Process Stack (TASKB)
unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;




unsigned int IRQ_Flag = 0;
unsigned int Task1_Flag = 0;
unsigned int Task2_Flag = 0;

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

	Task1_Flag = 0;
	Task2_Flag = 0;
	if(IRQ_Flag == 0)
	{
		Task1_Flag = 1;
		IRQ_Flag  = 1;

	}
	else
	{
		Task2_Flag = 1;
		IRQ_Flag = 0;

	}

}

int TaskA(int a, int b, int c)
{
	return a + b + c;
}

int TaskB(int a, int b, int c, int d)
{
	return a + b + c + d;
}

void MainOS()
{
	_E_MSP = (_S_MSP - 512);

	// TaskA
	_S_PSP_TA = (_E_MSP - 8);
	_E_PSP_TA = _S_PSP_TA - TaskA_Stack_Size;

	// TaskB
	_S_PSP_TB = (_E_PSP_TA - 8);
	_E_PSP_TB = _S_PSP_TB - TaskB_Stack_Size;

	while(1)
	{
		__asm("NOP");
		if(Task1_Flag == 1)
		{
			// 1- Set PSP register to _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);
			// 2- Switch SP -> PSP
			OS_SWITCH_SP_TO_PSP();

			// 3- Switch from privileged to unprivileged
			CPU_SwitchAccess(UNPRIVILAGED);
			// 4- Run the task
			TaskA(1, 2, 3);

			// 1- Switch from unprivileged to privileged
			OS_GENERATE_EXCEPTION();
			// 2- Switch SP -> MSP
			OS_SWITCH_SP_TO_MSP();

		}
		else if(Task2_Flag == 1)
		{

			// Set PSP register to _S_PSP_TB
			OS_SET_PSP(_S_PSP_TB);

			// 2- Switch SP -> PSP
			OS_SWITCH_SP_TO_PSP();

			// 3- Switch from privileged to unprivileged
			CPU_SwitchAccess(UNPRIVILAGED);

			TaskB(1, 2, 3, 4);

			// 1- Switch from unprivileged to privileged
			OS_GENERATE_EXCEPTION();
			// 2- Switch SP -> MSP
			OS_SWITCH_SP_TO_MSP();

		}
	}

}

int main(void)
{

	clock_init();
	LCD_Init();

	//CPU_SwitchAccess(UNPRIVILAGED);

	EXTI_PinConfig_t  EXTI_Config;
	EXTI_Config.EXTI_Pin = EXTI9PB9;
	EXTI_Config.IRQ_Enable = EXTI_IRQ_Enable;
	EXTI_Config.Trigger_Case = EXTI_FT;
	EXTI_Config.P_IRQ_CallBack = interrupt_callback;

	MCAL_EXTI_GPIO_Init(&EXTI_Config);
	MainOS();
	//CPU_SwitchAccess(UNPRIVILAGED);
	//CPU_SwitchAccess(PRIVILAGED);


	delay(50);
	//LCD_Write_String("Hello, worldHappy to see you today, thank youlol");
	while(1)
	{

		delay(1);
	}

}
