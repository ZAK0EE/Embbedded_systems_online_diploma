#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
# define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

int main()
{
	$fix$
	int m = 29;
	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n", m);

	int *ab = &m;
	printf("\nNow ab is assigned with the address of m.\n");
	printf("Address in pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	*ab = 34;
	printf("\nThe value of m assigned to 34 now.\n");
	printf("Address in pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
	printf("Address in pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);
	return 0;

}
