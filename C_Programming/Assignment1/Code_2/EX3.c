/* * main.c
 *
 *  Created on: 8/7/2021
 *  Author: Ziad
 */

#include <stdio.h>



int main()
{
	printf("Enter three numbers: ");
	fflush(stdout);
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);

	float largest = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
	printf("Largest number = %0.2f", largest);



	return 0;
}
