#ifndef INC_ALARMMONITOR_H_
#define INC_ALARMMONITOR_H_

#include "state.h"

//#define ALARM_MON_DEBUG
/*Global debugging*/
#ifdef HP_DEBUG
	#ifndef ALARM_MON_DEBUG
		#define ALARM_MON_DEBUG
	#endif
#endif

extern enum
{
	HP_ALARMON,
	HP_ALARMOFF,
	HP_ALARMWAITING,
	HP_ALARMNOTHING,
}alarm_mon_stateID;

STATE_DEFINE(HP_ALARMON);
STATE_DEFINE(HP_ALARMOFF);
STATE_DEFINE(HP_ALARMWAITING);
STATE_DEFINE(HP_ALARMNOTHING);

extern void (*alarm_mon_state)();
void HP_AlarmMon_init();


#endif /* INC_ALARMMONITOR_H_ */
