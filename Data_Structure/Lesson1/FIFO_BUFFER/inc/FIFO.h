/*
 * FIFO.h

 *
 *  Created on: 9/09
 *      Author: Ziad Gamalelden
 */

#ifndef INC_FIFO_H_
#define INC_FIFO_H_

#include <stdio.h>
#include <inttypes.h>

/*********User Configuration*********/

/*Modify ELEMENT_TYPE to the required data, e.g: int16_t, int32_t, ...*/
#define ELEMENT_TYPE uint32_t


/*********End of user configuration.*********/
typedef struct
{
	uint32_t length;
	uint32_t count;
	ELEMENT_TYPE *base;
	ELEMENT_TYPE *head;
	ELEMENT_TYPE *tail;
}FIFO_t;

typedef enum
{
	FIFO_FAIL = 0,
	FIFO_SUCC,
	FIFO_FULL,
	FIFO_EMPT,
	FIFO_NULL,
}FIFO_STATUS;
/*********FIFO_APIs*********/
FIFO_STATUS FIFO_init(FIFO_t* pfifo, ELEMENT_TYPE* buff, uint32_t length);
FIFO_STATUS FIFO_isfull(FIFO_t* pfifo);
FIFO_STATUS FIFO_isempty(FIFO_t* pfifo);
void	    FIFO_print(FIFO_t* pfifo);

FIFO_STATUS FIFO_enqueue(FIFO_t* pfifo, ELEMENT_TYPE item);
FIFO_STATUS FIFO_dequeue(FIFO_t* pfifo, ELEMENT_TYPE *item);

#endif /* INC_FIFO_H_ */
