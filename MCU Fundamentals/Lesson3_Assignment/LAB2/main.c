// Learn-in-depth
// Ziad Ashraf
// Mastering_Embedded System online diploma

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>


// Register address
#define GPIOA_BASE 	0x40010800
#define GPIOA_CRH 	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)

// Reset and clock control
#define RCC_BASE 0x40021000

// Clock control
#define RCC_CR	*(volatile uint32_t*)(RCC_BASE + 0x0)
#define HSION 0
#define HSIRDY 1
#define PLLON 24
// Clock configuration
#define RCC_CFGR	*(volatile uint32_t*)(RCC_BASE + 0x04)
#define SW 0 // System clock switch (0:1)
#define PPRE1 8 // APB1 prescaler (8:10)
#define PPRE2 11 // APB2 prescaler (11:13)
#define PLLSRC 16 // PLL entry clock source
#define PLLMUL 18 // PLL multiplication factor (18:21)

// APB2 peripherals
#define RCC_APB2ENR	*(volatile uint32_t *)(RCC_BASE + 0x18)

#define IOPAEN 2

int main(void)
{


	// Using internal 8 MHz RC oscillator
	RCC_CR |= (1 << HSION);

	// Enabling PLL (0: is off, 1: is on)
	RCC_CR |= (1 << PLLON);

	//0: HSI oscillator clock / 2 selected as PLL input clock
	//1: HSE oscillator clock selected as PLL input clock
	RCC_CFGR &= ~(1 << PLLSRC);

	/*Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8*/
	//RCC_CFGR = ((RCC_CFGR & ~( 0xF << PLLMUL)) | (0x6 << PLLMUL));
	RCC_CFGR |= (0b0110 << PLLMUL);
	/*Bits 1:0 SW: System clock switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed*/
	RCC_CFGR = ((RCC_CFGR & ~( 0x3 << SW)) | (0b10 << SW));

	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR = ((RCC_CFGR & ~( 0x7 << PPRE1)) | (0x4 << PPRE1));

	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR = ((RCC_CFGR & ~( 0x7 << PPRE2)) | (0x5 << PPRE2));


	// Enabling PORTA clock
	RCC_APB2ENR |= (1 << IOPAEN);

	// Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for(int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for(int i = 0; i < 5000; i++); // arbitrary delay
	}
}
