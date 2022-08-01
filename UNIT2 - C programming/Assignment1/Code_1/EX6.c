/* * main.c
 *
 *  Created on: 7/7/2021
 *  Author: Ziad
 */

#include <stdio.h>

int main()
{
	float a, b;
	/*Entry of a.*/
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f", &a);
	fflush(stdin);
	/*Entry of b.*/
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f", &b);
	fflush(stdin);
	/*Swapping*/
	float temp = a;
	a = b;
	b = temp;

	printf("\nAfter swapping, value of a = %0.2f\n", a);
	fflush(stdout);
	printf("After swapping, value of b = %0.2f\n", b);
	return 0;
}
