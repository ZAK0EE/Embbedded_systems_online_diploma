#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

#define PI 3.14
#define AREA(r) ((r) * (r) * PI)

int main()
{
	$fix$
	float r;
	printf("Enter radius: ");
	scanf("%f", &r);
	
	printf("Area = %0.2f", AREA(r));
	

	return 0;
}
