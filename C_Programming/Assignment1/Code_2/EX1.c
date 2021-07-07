/* * main.c
 *
 *  Created on: 7/7/2021
 *  Author: Ziad
 */

#include <stdio.h>

int main()
{
	int input;
	printf("Enter an integer you want to check: ");
	fflush(stdout);

	scanf("%d", &input);
	fflush(stdin);

	printf("%d is %s", input, (input % 2) ? "odd" : "even");

	return 0;
}
