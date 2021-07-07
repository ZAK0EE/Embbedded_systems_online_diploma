/* * main.c
 *
 *  Created on: 7/7/2021
 *  Author: Ziad
 */

#include <stdio.h>

int main()
{
	float input1, input2;

	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%f%f", &input1, &input2);
	fflush(stdin);
	printf("Product: %0.2f", input1 * input2);

	return 0;
}
