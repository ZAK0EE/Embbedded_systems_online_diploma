/* * main.c
 *
 *  Created on: 8/7/2021
 *  Author: Ziad
 */

#include <stdio.h>
#include <ctype.h>


int main()
{
	printf("Enter an integer: ");
	fflush(stdout);
	int n;
	scanf("%d", &n);


	printf("Sum = %d", n * (n + 1) / 2);



	return 0;
}
