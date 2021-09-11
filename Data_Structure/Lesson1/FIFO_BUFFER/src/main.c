/*
 * main.c

 *
 *  Created on: 9/09
 *      Author: Ziad Gamalelden
 */
#include <stdio.h>
#include "FIFO.h"
#include <inttypes.h>
#define LENGTH 5
uint32_t buff[LENGTH];

int main()
{
	FIFO_t UART_fifo;
	if(FIFO_init(&UART_fifo, buff, LENGTH) == FIFO_SUCC)
		printf("Fifo initialized sucessfully..\n");
	else
		return 1;
	uint32_t i;

	for(i = 0; i < 7; i++)
	{
		printf("Enqueuing: %d\n", i);
		if(FIFO_isfull(&UART_fifo))
		{
			printf("Operation failed on i = %d\nERROR: FIFO IS FULL!\n", i);
		}
		else
			FIFO_enqueue(&UART_fifo, i);
	}
	printf("\n\n");
	/*Printing*/
	if(!FIFO_isempty(&UART_fifo))
		FIFO_print(&UART_fifo);
	printf("\n\n");
	/*Dequeuing*/
	uint32_t temp;
	if(!FIFO_isempty(&UART_fifo))
	{
		FIFO_dequeue(&UART_fifo, &temp);
		printf("%d is dequeued\n", temp);
	}
	if(!FIFO_isempty(&UART_fifo))
	{
		FIFO_dequeue(&UART_fifo, &temp);
		printf("%d is dequeued\n", temp);
	}
	printf("\n\n");
	/*Printing*/
	if(!FIFO_isempty(&UART_fifo))
		FIFO_print(&UART_fifo);

}


