#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

/*Factorial for positive numbers.*/
int Fact(int num)
{
	if(num <= 1)
		return 1;
	return num * Fact(num - 1);

}

int main()
{
	$fix$
	int num;
	printf("Enter a positive number: ");
	scanf("%d", &num);
	printf("Factorial of %d is: %d", num, Fact(num));


	return 0;
}

