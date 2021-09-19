/*
 * HP_detector.h
 */

#ifndef INC_HP_DETECTOR_H_
#define INC_HP_DETECTOR_H_
#include "state.h"

//#define DETECTOR_DEBUG
/*Global debugging*/
#ifdef HP_DEBUG
	#ifndef DETECTOR_DEBUG
		#define DETECTOR_DEBUG
	#endif
#endif

extern enum
{
	HP_DETECTOR_READING,
}detector_stateID;

STATE_DEFINE(HP_DETECTOR_READING);

extern void (*detector_state)();
void HP_detector_init();


#endif /* INC_HP_DETECTOR_H_ */
