#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

/*Print string in reverse*/
void rprint(char* a)
{
	if(*a == '\0')
		return;
	rprint(a + 1);
	printf("%c", *a);

}

int main()
{
	$fix$
	char word[100];
	printf("Enter a sentence: ");
	gets(word);
	rprint(word);


	return 0;
}

