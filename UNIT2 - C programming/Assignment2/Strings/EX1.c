#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	char string[100], ch;
	int count = 0, i;

	printf("Enter a string: ");
	gets(string);

	printf("Enter a character to find frequency: ");
	fflush(stdin);
	scanf("%c", &ch);
	ch = tolower(ch);
	/*Calculate frequency for the character, ignoring upper or smaller*/
	for(i = 0; string[i] != 0; i++)
	{
		if (tolower(string[i]) == ch)
			count++;
	}
	printf("Frequency of %c is : %d", ch, count);

	return 0;
}
