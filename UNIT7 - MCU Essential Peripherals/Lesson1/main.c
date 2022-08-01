// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>


// PORTA memory-mapping
#define GPIOA_BASE 	0x40010800
#define GPIOA_CRL 	*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH 	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR	*(volatile uint32_t *)(GPIOA_BASE + 0x08)


// PORTB memory-mapping
#define GPIOB_BASE 	0x40010C00
#define GPIOB_CRL 	*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH 	*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR	*(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR	*(volatile uint32_t *)(GPIOB_BASE + 0x08)

// Port configuration register low (GPIOx_CRL)
#define MODE1 4
#define CNF1  6

// Port configuration register high (GPIOx_CRH)
#define MODE13 20
#define CNF13  22

// Reset and clock control
#define RCC_BASE 0x40021000

// Clock control
#define RCC_CR	*(volatile uint32_t*)(RCC_BASE + 0x0)
#define HSION 0
#define HSIRDY 1
#define PLLON 24

// Clock configuration
#define RCC_CFGR	*(volatile uint32_t*)(RCC_BASE + 0x04)

// APB2 peripherals
#define RCC_APB2ENR	*(volatile uint32_t *)(RCC_BASE + 0x18)

#define IOPAEN 2 // IO port A clock enable
#define IOPBEN 3 // IO pot B clock enable





void clock_init()
{
	// Using internal 8 MHz RC oscillator
	RCC_CR |= (1 << HSION);

}

void GPIO_init()
{
	// Enabling PORTA clock
	RCC_APB2ENR |= (1 << IOPAEN) | (1 << IOPBEN);



	// Initializing GPIOA
	GPIOA_CRL = 0;
	// PIN 1 is input - open drain
	GPIOA_CRL &= ~(0b11 << MODE1); // 00: Input mode (reset state)
	GPIOA_CRL |= (0b01 << CNF1); // 01: Floating input (reset state)

	// PIN 13 is input - open drain
	GPIOA_CRH &= ~(0b11 << MODE13); // 00: Input mode (reset state)
	GPIOA_CRH |= (0b01 << CNF13); // 01: Floating input (reset state)

	// Initializing GPIOB
	GPIOB_CRL = 0;

	// PIN 1 is output - push-pull
	GPIOB_CRL |= (0b01 << MODE1); // 01: Output mode, max speed 10 MHz
	GPIOB_CRL |= (0b01 << CNF1); // 01: General purpose output Open-drain

	// PIN 13 is output - push-pull
	GPIOB_CRH |= (0b01 << MODE13); // 01: Output mode, max speed 10 MHz
	GPIOB_CRH |= (0b01 << CNF13); // 01: General purpose output Open-drain


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



	GPIOB_ODR = ~(0);
	int prevValue = 1;
	int currentValue = 1;
	while(1)
	{
		currentValue = (GPIOA_IDR & (1 << 1)) >> 1;
		// Single press
		if(prevValue != currentValue)
		{
			if(currentValue == 0)
				GPIOB_ODR ^= (1 << 1);
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
		if((GPIOA_IDR & (1 << 13)))
		{
			GPIOB_ODR ^= (1 << 13);
		}
		delay(1);
	}

}
