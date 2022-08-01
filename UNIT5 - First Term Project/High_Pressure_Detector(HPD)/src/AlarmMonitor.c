#include "AlarmMonitor.h"
#include "driver.h"

#ifdef ALARM_MON_DEBUG
#define  DPRINT(msg)  printf msg
#else
#define  DPRINT(msg)    /* NOT IN DEBUG MODE */
#endif

static int AlarmTime = 60;

void (*alarm_mon_state)();

void HP_hpDetected()
{
	alarm_mon_state = STATE(HP_ALARMON);
	DPRINT(("Detector >>> AlarmMonitor: High Pressure detected!\n"));
}
STATE_DEFINE(HP_ALARMON)
{
	DPRINT(("HP_MON_ALARMON: Alerting actuator.\n"));

	HP_startAlarm();

	/*Go into waiting state FOR 60 seconds*/
	alarm_mon_state = STATE(HP_ALARMWAITING);



}

STATE_DEFINE(HP_ALARMOFF)
{
	DPRINT(("HP_ALARMOFF: Halting Actuator\n"));
	HP_stopAlarm();
	alarm_mon_state = STATE(HP_ALARMNOTHING);

}

STATE_DEFINE(HP_ALARMWAITING)
{
	/*An example of how we can make a waiting state with the consideration of the allowed delay per program loop*/
	static int minute = 0;
	Delay(9000);
	minute++;
	if(minute == AlarmTime)
	{
		minute = 0;
		alarm_mon_state = STATE(HP_ALARMOFF);
	}
	DPRINT(("HP_ALARMWAITING: Alarm is still on\n"));


}
/*Simply do nothing while no high pressure detected*/
STATE_DEFINE(HP_ALARMNOTHING){}
void HP_AlarmMon_init()
{
	alarm_mon_state = STATE(HP_ALARMOFF);
	DPRINT(("HP alarm monitor initialized\n", 0));
}
