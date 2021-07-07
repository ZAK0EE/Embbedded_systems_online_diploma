/* * main.c
 *
 *  Created on: 8/7/2021
 *  Author: Ziad
 */

#include <stdio.h>
#include <ctype.h>


int main()
{
	printf("Enter a character: ");
	fflush(stdout);
	char input;
	scanf("%c", &input);


	if(tolower(input) >= 'a' && tolower(input) <= 'z')
		printf("%c is an alphabet", input);
	else
		printf("%c is not an alphabet", input);



	return 0;
}
