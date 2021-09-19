/*
 * HP_detector.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Fury Word
 */
#include "HP_detector.h"
#include <stdio.h>


#ifdef DETECTOR_DEBUG
#define  DPRINT(msg)  printf msg
#else
#define  DPRINT(msg)    /* NOT IN DEBUG MODE */
#endif

static int pressVal = 0;
static int pressThreshold = 20;

void (*detector_state)();
/*Connection between sensor and detector*/
void HP_setPressVal(int pressure)
{
	pressVal = pressure;
	DPRINT(("Sensor >>> Detector: Pressure Value = %d\n", pressVal));
}

STATE_DEFINE(HP_DETECTOR_READING)
{


	if(pressVal > pressThreshold)
	{
		DPRINT(("HP_DETECTOR_READING: Pressure Value = %d, -HP DETECTED-\n", pressVal));
		HP_hpDetected();

	}
	else
	{
		DPRINT(("HP_DETECTOR_READING: Pressure Value = %d, -HP NOT DETECTED-\n", pressVal));
	}



}

void HP_detector_init()
{
	detector_state = STATE(HP_DETECTOR_READING);
	DPRINT(("HP detector initialized\n"));
}
