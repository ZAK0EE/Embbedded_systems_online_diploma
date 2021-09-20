#include "AlarmActuator.h"
#include <stdio.h>
#include "driver.h"
#ifdef ALARM_ACT_DEBUG
#define  DPRINT(msg)  printf msg
#else
#define  DPRINT(msg)    /* NOT IN DEBUG MODE */
#endif

void (*alarm_act_state)();
void HP_startAlarm()
{
	alarm_act_state = STATE(HP_ACT_ALARMON);
	alarm_act_state();
}
void HP_stopAlarm()
{
	alarm_act_state = STATE(HP_ACT_ALARMOFF);
	alarm_act_state();
}
STATE_DEFINE(HP_ACT_ALARMON)
{
#ifndef ALARM_ACT_DEBUG
	Set_Alarm_actuator(0);

#endif
	DPRINT(("HP_ACT_ALARMON: Alarm is on.\n"));
}
STATE_DEFINE(HP_ACT_ALARMOFF)
{
#ifndef ALARM_ACT_DEBUG
	Set_Alarm_actuator(1);
#endif
	DPRINT(("HP_ACT_ALARMON: Alarm is off.\n"));
}


void (*alarm_act_state)();
void HP_AlarmAct_init()
{
	alarm_act_state = STATE(HP_ACT_ALARMOFF);
}

