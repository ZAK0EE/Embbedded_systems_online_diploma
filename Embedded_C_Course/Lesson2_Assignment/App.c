#include <UART.h>
#include <string.h>
 unsigned char 	strbuff0[100] = "Learn_In_Depth: Ziad";
 unsigned char  const strbuff1[100] = "Store me in RODATA";
void main(void)
{
	//strcpy(strbuff2, "looool this is weird"); 
	uart0_sendstr(strbuff0);
}
