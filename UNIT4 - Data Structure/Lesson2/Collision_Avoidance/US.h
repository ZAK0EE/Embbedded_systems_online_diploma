
#ifndef US_H_
#define US_H_

#include "state.h"

enum
{
	US_busy,
}US_state_id;

STATE_DEFINE(US_busy);

extern void (*US_state)();

void US_init();

#endif /* US_H_ */
