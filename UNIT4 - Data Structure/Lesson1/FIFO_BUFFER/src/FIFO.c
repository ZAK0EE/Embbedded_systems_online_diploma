/*
 * FIFO.c

 *
 *  Created on: 9/09
 *      Author: Ziad Gamalelden
 */
#include "FIFO.h"
FIFO_STATUS FIFO_init(FIFO_t* pfifo, ELEMENT_TYPE* buff, uint32_t length)
{
	if(buff == NULL)
		return FIFO_FAIL;
	pfifo->base = pfifo->head = pfifo->tail = buff;
	pfifo->length = length;
	pfifo->count = 0;
	return FIFO_SUCC;
}

FIFO_STATUS FIFO_isfull(FIFO_t* pfifo)
{
	return (pfifo->count == pfifo->length);
}

FIFO_STATUS FIFO_isempty(FIFO_t* pfifo)
{
	return (pfifo->count == 0);
}

void FIFO_print(FIFO_t* pfifo)
{
	ELEMENT_TYPE *hcurs = pfifo->head;
	while(hcurs != pfifo->tail)
	{
		if(hcurs == (pfifo->base + pfifo->length * sizeof(ELEMENT_TYPE)))
				hcurs = pfifo->base;
		printf("FIFO_ELEMENT: %d\n", *hcurs);
		hcurs++;
	}
}

/*tail here is considered to be the end of the queue.*/
FIFO_STATUS FIFO_enqueue(FIFO_t* pfifo, ELEMENT_TYPE item)
{
	*(pfifo->tail) = item;
	pfifo->count++;
	pfifo->tail++;
	/*Circulation check*/
	if(pfifo->tail == (pfifo->base + pfifo->length * sizeof(ELEMENT_TYPE)))
		pfifo->tail = pfifo->base;

	return FIFO_SUCC;
}
FIFO_STATUS FIFO_dequeue(FIFO_t* pfifo, ELEMENT_TYPE *item)
{
	*item = *(pfifo->head);
	pfifo->count--;
	pfifo->head++;
	if(pfifo->head == (pfifo->base + pfifo->length * sizeof(ELEMENT_TYPE)))
		pfifo->head = pfifo->base;
	return FIFO_SUCC;
}

