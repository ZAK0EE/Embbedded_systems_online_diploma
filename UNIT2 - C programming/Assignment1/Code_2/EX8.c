/* * main.c
 *
 *  Created on: 8/7/2021
 *  Author: Ziad
 */

#include <stdio.h>
#include <ctype.h>


int main()
{
	printf("Enter an operator either + or - or * or / : - ");
	fflush(stdout);

	char op;
	scanf("%c", &op);
	fflush(stdin);

	float a, b;
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f%f", &a, &b);
	fflush(stdin);

	float ans = 0;
	switch(op)
	{
	case '+':
		ans = a + b;
		break;
	case '-':
		ans = a - b;
		break;
	case '*':
		ans = a * b;
		break;
	case '/':
		if (b == 0)
		{
			printf("CANNOT DIVIDE BY ZERO\n");
			return 1;
		}
		else
			ans = a / b;
		break;
	default:
		printf("Please enter proper operator.\n");
		return 2;

	}
	printf("%0.2f %c %0.2f =  %0.2f", a, op, b, ans);





	return 0;
}
