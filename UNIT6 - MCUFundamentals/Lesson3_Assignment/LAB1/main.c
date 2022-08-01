// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>


// Register address
#define GPIOA_BASE	0x40010800
#define GPIOA_CRH	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)

// Reset and clock control
#define RCC_BASE	0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE + 0x18)
#define IOPAEN 2

int main(void)
{
	// Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	
	// Enabling PORTA clock
	RCC_APB2ENR |= (1 << IOPAEN);
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for(int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for(int i = 0; i < 5000; i++); // arbitrary delay
	}
}
