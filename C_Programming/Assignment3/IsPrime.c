#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

/*IsPrime for positive numbers.*/
int IsPrime(int num)
{
	if(num < 2)
		return 0;

	int i;
	for(i = 2; i < num; i ++)
		if(num % i == 0 && num != i)
			return 0;
	return 1;

}

int main()
{
	$fix$
	int start, end;
	printf("Enter two numbers(intervals): ");
	scanf("%d %d", &start, &end);
	printf("Prime numbers between %d and %d are : ", start, end);
	for(; start <= end; start++)
		if(IsPrime(start))
			printf("%d ", start);


	return 0;
}
