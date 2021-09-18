
#ifndef DC_H_
#define DC_H_

#include "state.h"

enum
{
	DC_idle,
	DC_busy,
}DC_state_id;

STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

extern void (*DC_state)();
void DC_init();


#endif /* DC_H_ */
