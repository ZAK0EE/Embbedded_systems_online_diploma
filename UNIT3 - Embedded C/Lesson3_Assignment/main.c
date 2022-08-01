#include "PlatformTypes.h"

#define RCC_BASE 	0x40021000
#define GPIOA_BASE	0x40010800

#define RCC_APB2NR	*(volatile uint32*)(RCC_BASE + 0x18)

#define GPIOA_CRH	*(volatile uint32*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(volatile uint32*)(GPIOA_BASE + 0x0C)

#define RCC_IOPAEN (1<<2)

typedef union
{
	uint16 all_bits;
	struct
	{
		uint16 reserved:13;
		uint16 P13:1;
	}PIN;
}PORT;

volatile PORT* PORTA = (volatile PORT*)(GPIOA_BASE + 0X0C);
unsigned char g_variables[3] = {1, 2, 3};
unsigned char uninitialized[50];
unsigned char const const_variables[3] = {1, 2, 3};
extern void NMI_Handler(){}

int main(void)
{

	RCC_APB2NR |= RCC_IOPAEN; //Enables GPIOA
	GPIOA_CRH &= ~(0xf << (4 * 5));
	GPIOA_CRH |=  (0X2 << (4 * 5));

	int i;
    /* Loop forever */
	while(1)
	{
		PORTA->PIN.P13 ^= 1;;
		
		for(i = 0; i < 500000; i++);
	}
}
