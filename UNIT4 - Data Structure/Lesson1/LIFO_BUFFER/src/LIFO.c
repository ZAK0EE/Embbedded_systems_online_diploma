/*
 * lifo.c
 *
 *  Created on: 07/09/2021
 *  Author: Ziad Gamalelden
 */
#include "LIFO.h"

LIFO_STATUS LIFO_init(LIFO_t* plifo, ELEMENT_TYPE *buff, uint32_t length)
{
		if(buff == NULL)
			return LIFO_NULL;
		plifo->base = plifo->head = buff;
		plifo->length = length;
		plifo->count = 0;
		return LIFO_SUCC;
}

LIFO_STATUS	LIFO_isempty(LIFO_t *plifo)
{
	return (plifo->count == 0);
}

LIFO_STATUS	LIFO_isfull(LIFO_t *plifo)
{
	return (plifo->count == plifo->length);
}

LIFO_STATUS LIFO_push(LIFO_t* plifo, ELEMENT_TYPE item)
{
	*(plifo->head) = item;
	plifo->head++;
	plifo->count++;

	return LIFO_SUCC;
}

LIFO_STATUS LIFO_pop(LIFO_t* plifo, ELEMENT_TYPE *item)
{
	plifo->head--;
	*item = *(plifo->head);
	plifo->count--;

	return LIFO_SUCC;
}

