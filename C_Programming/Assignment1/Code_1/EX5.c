/* * main.c
 *
 *  Created on: 7/7/2021
 *  Author: Ziad
 */

#include <stdio.h>

int main()
{
	char input;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c", &input);
	fflush(stdin);
	printf("ASCII value of %c = %d", input, input);

	return 0;
}
