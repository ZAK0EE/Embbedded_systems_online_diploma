/*
 * main.c
 *
 *  Created on: 18/9/2021
 *      Author: Ziad Gamalelden
 */
#include <stdio.h>
#include "HP_sensor.h"
#include "HP_detector.h"
#include "AlarmMonitor.h"
#include "AlarmActuator.h"
#include "driver.h"
void setup()
{
	//init all drivers.
	GPIO_INITIALIZATION ();
	HP_sensor_init();
	HP_detector_init();
	HP_AlarmMon_init();
	HP_AlarmAct_init();
}

int main()
{

	setup();
	while(1)
	{
		sensor_state();
		detector_state();
		alarm_mon_state();
		//Delay(99999999);

	}
}


