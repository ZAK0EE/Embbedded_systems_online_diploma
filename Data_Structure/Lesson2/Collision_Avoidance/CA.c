#include "CA.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


void (*CA_state)();

void US_set_distance(int d)
{
	CA_distance = d;
	CA_state = (CA_distance > CA_threshold) ? STATE(CA_driving) : STATE(CA_waiting);
	printf("US-----distance = %d------>CA\n", CA_distance);
}
STATE_DEFINE(CA_waiting)
{
	/*state name*/
	CA_state_id = CA_waiting;
	printf("CA_waiting state: distance = %d, speed = %d\n", CA_distance, CA_speed);
	/*state action*/
	CA_speed = 0;
	DC_motor_set(CA_speed);
}

STATE_DEFINE(CA_driving)
{
	/*state name*/
	CA_state_id = CA_driving;
	printf("CA_driving state: distance = %d, speed = %d\n", CA_distance, CA_speed);
	/*state action*/
	CA_speed = 30;
	DC_motor_set(CA_speed);
}

