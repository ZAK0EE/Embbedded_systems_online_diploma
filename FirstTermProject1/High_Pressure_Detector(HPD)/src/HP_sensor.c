#include "HP_sensor.h"
#include <stdlib.h>

static unsigned int pressVal = 0;

#ifdef SENSOR_DEBUG
#define  DPRINT(msg)  printf msg
#else
#define  DPRINT(msg)    /* NOT IN DEBUG MODE */
#endif

void (*sensor_state)();
STATE_DEFINE(HP_SENSOR_READING)
{

#ifdef SENSOR_DEBUG
	pressVal = (rand() % 11) + 15;
#else
	pressVal = getPressureVal();
#endif

	DPRINT(("HP_SENSOR_READING: Pressure Value = %d\n", pressVal));
	HP_setPressVal(pressVal);
	Delay(1000);
}


void HP_sensor_init()
{
	sensor_state = STATE(HP_SENSOR_READING);
	DPRINT(("HP sensor initialized\n"));
}
