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

	if (n < 0)
	{
		printf("factorial does not exist !");
		return 1;
	}
	long long ans = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		ans *= i;
	}
	printf("factorial is : %lu", ans);



	return 0;
}
