#include <UART.h>
//UART Data Register
#define UART0DR  *((volatile unsigned int* const)((unsigned int*)0x101f1000))

void uart0_sendstr(unsigned char  *P_tx_str)
{
	while(*P_tx_str != '\0')
	{
		UART0DR = (unsigned int)(*P_tx_str);
		P_tx_str++;
	}
}