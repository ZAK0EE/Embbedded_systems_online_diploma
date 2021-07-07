/* * main.c
 *
 *  Created on: 7/7/2021
 *  Author: Ziad
 */

#include <stdio.h>

int main()
{
	int input1, input2;

	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d%d", &input1, &input2);
	fflush(stdin);
	printf("Sum: %d", input1 + input2);

	return 0;
}
