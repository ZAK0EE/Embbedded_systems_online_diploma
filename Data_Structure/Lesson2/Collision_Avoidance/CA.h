
#ifndef CA_H_
#define CA_H_

#include "state.h"

enum
{
	CA_waiting,
	CA_driving,
}CA_state_id;

STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

extern void (*CA_state)();


#endif /* CA_H_ */
