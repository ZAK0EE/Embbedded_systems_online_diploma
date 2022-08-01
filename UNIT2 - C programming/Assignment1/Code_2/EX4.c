/* * main.c
 *
 *  Created on: 8/7/2021
 *  Author: Ziad
 */

#include <stdio.h>



int main()
{
	printf("Enter a number: ");
	fflush(stdout);
	float input;
	scanf("%f", &input);

	if (input > 0)
		printf("%.2f is positive", input);
	else if (input < 0)
		printf("%.2f is negative", input);
	else
		printf("You entered zero");
	printf("\n");



	return 0;
}
