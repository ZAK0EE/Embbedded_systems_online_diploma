/*
 * lifo.h

 *
 *  Created on: 07/09/2021
 *  Author: Ziad Gamalelden
 */
#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <inttypes.h>

/*Note: Lifo elements MUST_BE unsigned integers*/
/*********User Configuration*********/

/*Modify ELEMENT_TYPE to the required data, e.g: int16_t, int32_t, ...*/
#define ELEMENT_TYPE uint32_t


/*********End of user configuration.*********/
/*Type definitions*/
typedef struct
{
	uint32_t length;
	uint32_t count;
	ELEMENT_TYPE *base;
	ELEMENT_TYPE *head;
}LIFO_t;

typedef enum
{
	LIFO_FAIL = 0,
	LIFO_SUCC,
	LIFO_FULL,
	LIFO_EMPT,
	LIFO_NULL,
}
LIFO_STATUS;


LIFO_STATUS LIFO_init(LIFO_t* plifo, ELEMENT_TYPE *buff, uint32_t length);
LIFO_STATUS	LIFO_isempty(LIFO_t *plifo);
LIFO_STATUS	LIFO_isfull(LIFO_t *plifo);
LIFO_STATUS LIFO_push(LIFO_t* plifo, ELEMENT_TYPE item);
LIFO_STATUS LIFO_pop(LIFO_t* plifo, ELEMENT_TYPE *item);




#endif /* LIFO_H_ */
