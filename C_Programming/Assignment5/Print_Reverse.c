#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
# define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

int main()
{
	$fix$
	char input[50];
	printf("Input a string: ");
	scanf("%s", input);

	printf("The reverse of the string is: ");
	char *pch = input + strlen(input) - 1;
	while(input <= pch)
	{
		printf("%c", *pch);
		pch--;
	}
	return 0;

}
