#ifndef INC_HP_SENSOR_H_
#define INC_HP_SENSOR_H_
#include "driver.h"
#include "state.h"

//#define SENSOR_DEBUG
/*Global debugging*/
#ifdef HP_DEBUG
	#ifndef SENSOR_DEBUG
		#define SENSOR_DEBUG
	#endif
#endif

extern enum
{
	HP_SENSOR_READING,
}sensor_stateID;

STATE_DEFINE(HP_SENSOR_READING);

extern void (*sensor_state)();
void HP_sensor_init();

#endif /* INC_HP_SENSOR_H_ */
