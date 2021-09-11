/*
 ============================================================================

         LIFO_BUFFER.c
 Author      : Ziad Gamalelden
 Version     : Alpha
 Copyright   : 
 Description : LIFO_BUFFER data structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "LIFO.h"

uint32_t buff1[5];

int main(void)
{
	LIFO_t UART_lifo, I2C_lifo;
	//Static LIFO
	LIFO_init(&UART_lifo, buff1, 5);

	//Dynamic LIFO
	uint32_t *buff2 = (uint32_t *)malloc(5 * sizeof(int));

	LIFO_init(&I2C_lifo, buff2, 5);

	uint32_t i;
	//Fill UART buffer.
	for(i = 0; i < 5; i++)
	{
		if(!LIFO_isfull(&UART_lifo))
		{
			if(LIFO_push(&UART_lifo, i) == LIFO_SUCC)
				printf("UART_LIFO: %d added.\n", i);
		}
		else
			printf("LIFO IS FULL\n");

	}
	printf("\n");

	//Empty UART buffer.
	uint32_t temp;
	for(i = 0; i < 5; i++)
	{
		if(!LIFO_isempty(&UART_lifo))
		{
			if(LIFO_pop(&UART_lifo, &temp) == LIFO_SUCC)
				printf("UART_LIFO: %d popped.\n", temp);
		}
		else
				printf("LIFO IS EMPTY\n");
	}


}
