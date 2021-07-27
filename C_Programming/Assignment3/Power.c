#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

/*Power for positive numbers.*/
int Power(int num, int power)
{
	if(power == 1)
		return 1;
	return num * Power(num, power - 1);

}

int main()
{
	$fix$
	int num, power;
	printf("Enter base number: ");
	scanf("%d", &num);
	printf("Enter power number(positive): ");
	scanf("%d", &power);
	printf("%d ^ %d = %d", num, power, Power(num, power));


	return 0;
}

