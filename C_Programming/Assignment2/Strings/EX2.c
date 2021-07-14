#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	char string[100];
	int count = 0, i;

	printf("Enter a string: ");
	gets(string);


	for(i = 0; string[i] != 0; i++)
		count++;

	printf("Length of the string is : %d", count);

	return 0;
}
