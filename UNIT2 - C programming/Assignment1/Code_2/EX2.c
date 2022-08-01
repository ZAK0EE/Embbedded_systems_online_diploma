/* * main.c
 *
 *  Created on: 8/7/2021
 *  Author: Ziad
 */

#include <stdio.h>
#include <stdbool.h>

#define NVOWELS 5

int main()
{
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	char input;

	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c", &input);
	fflush(stdin);
	
	int i;
	bool vowel = false;
	for(i = 0; i < NVOWELS; i++)
	{
		if (input == vowels[i])
		{
			vowel = true;
			break;
		}
	}
	if (vowel)
		printf("%c is a vowel.", input);
	else
		printf("%c is a consonant", input);
	
	return 0;
}
