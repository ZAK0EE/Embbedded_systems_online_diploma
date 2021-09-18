#include <stdio.h>
#include "CA.h"
#include "US.h"
#include "DC.h"
#include <Windows.h>
void setup()
{
	//init all drivers.
	//init interrupts.
	US_init();
	DC_init();
	//init HAL(hardware abstraction layer)-> Ultra sonic sensor
	//set states pointer for each block like CA
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
int main()
{
	$fix$
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		Sleep(1000);
	}

}
