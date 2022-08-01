#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	char string[100];
	int i;

	printf("Enter a string: ");
	gets(string);

	printf("Reverse string is : ");
	for(i = strlen(string) - 1; i >= 0; i--)
		printf("%c", string[i]);

	return 0;
}
