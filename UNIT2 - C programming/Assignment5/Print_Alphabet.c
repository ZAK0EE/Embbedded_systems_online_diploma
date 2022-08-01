#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
# define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

int main()
{
	$fix$
	char alpha[26];
	int i;
	for(i = 0; i < 26; i++)
	{
		alpha[i] = 'A' + i;
	}

	char *pch = alpha;

	for(i = 0; i < 26; i++)
	{
		printf("%c ", *pch);
		pch++;
	}
	return 0;

}
