#include "US.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int US_speed = 0;
int US_distance = 0;
int US_threshold = 50;


void (*US_state)();

STATE_DEFINE(US_busy)
{
	US_distance = ((rand() % 11) + 45);
	printf("US_waiting state: distance = %d\n", US_distance);
	US_set_distance(US_distance);
	US_state = STATE(US_busy);
	return ;
}

void US_init()
{
	/*init US driver*/
	printf("US initialized\n");
}



