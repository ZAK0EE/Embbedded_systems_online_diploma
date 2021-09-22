/*
 * main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
#include "SDM.h"



#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
int main()
{
	$fix$
	SDM_MenuScreen();

}

