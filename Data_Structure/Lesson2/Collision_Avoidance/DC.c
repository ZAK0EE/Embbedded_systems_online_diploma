#include "DC.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DC_speed = 0;



void (*DC_state)();

void DC_motor_set(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA-----speed = %d------>DC\n", DC_speed);

}
void DC_init()
{
	/*init DC/PWM drivers*/
	printf("DC initialized\n");
}
STATE_DEFINE(DC_idle)
{
	/*state name*/
	DC_state_id = DC_idle;
	/*state action*/
	/*Keep current speed*/

	printf("DC_idle state: speed = %d\n", DC_speed);
}

STATE_DEFINE(DC_busy)
{
	/*state name*/
	DC_state_id = DC_busy;
	/*state action*/
	/*Call PWM to achieve required speed = DC_speed*/

	DC_state = STATE(DC_idle);
	printf("DC_busy state: speed = %d\n", DC_speed);
}

