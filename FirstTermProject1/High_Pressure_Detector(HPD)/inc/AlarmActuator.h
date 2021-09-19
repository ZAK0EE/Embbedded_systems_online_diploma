#ifndef INC_ALARMACTUATOR_H_
#define INC_ALARMACTUATOR_H_
#include "state.h"

//#define ALARM_ACT_DEBUG
/*Global debugging*/
#ifdef HP_DEBUG
	#ifndef ALARM_ACT_DEBUG
		#define ALARM_ACT_DEBUG
	#endif
#endif

extern enum
{
	HP_ACT_ALARMON,
	HP_ACT_ALARMOFF,

}alarm_act_stateID;

STATE_DEFINE(HP_ACT_ALARMON);
STATE_DEFINE(HP_ACT_ALARMOFF);


extern void (*alarm_act_state)();
void HP_AlarmAct_init();

#endif /* INC_ALARMACTUATOR_H_ */
