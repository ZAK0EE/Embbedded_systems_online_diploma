//Startup.c
//Eng:Ziad Gamalelden
#include <stdio.h>
#include <inttypes.h>

void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak, alias("Default_Handler"))); 
void H_Fault_Handler()__attribute__((weak, alias("Default_Handler")));



extern int main(void);
//Reserving 1024B located in .bss section by using an uninitialized array of 256 int element (256 * 4 = 1024)
static uint32_t Stack_top[256];

void (*const vectors[])() __attribute__((section(".vectors"))) =
{
	(void (*)())((uint32_t)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,

	
};
extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
void Reset_Handler()
{
	//Copy data section from Flash to SRAM
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char *P_src = (unsigned char*)&_E_text;
	unsigned char *P_dis = (unsigned char*)&_S_DATA;
	while(DATA_size--)
	{
		*P_dis++ = *P_src++;
	}
	//Initialzing bss section.
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dis = (unsigned char*)&_S_bss;
	while(bss_size--)
	{
		*P_dis++ = (unsigned char)0;
	}
	//Jump main
	main();
}

