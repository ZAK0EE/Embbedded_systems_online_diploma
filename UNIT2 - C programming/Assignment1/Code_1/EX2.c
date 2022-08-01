/* * main.c
 *
 *  Created on: 7/7/2021
 *  Author: Ziad
 */

#include <stdio.h>

int main()
{
	int input;

	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &input);
	fflush(stdin);
	printf("You entered: %d", input);

	return 0;
}
