#include <stdio.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	float num[100];
	int i, j; /* counters*/
	int n = 0;

	printf("Enter the number of data: ");
	scanf("%d", &n);
	/*Storing data.*/
	for (i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i + 1);
		scanf("%f", &num[i]);
	}
	/*Calculating averge*/
	float sum = 0;
	for (i = 0; i < n; i++)
		sum += num[i];

	printf("Average = %f", sum / n);



	return 0;
}
