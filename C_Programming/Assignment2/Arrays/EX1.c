#include <stdio.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	float a[2][2], b[2][2];
	/*Matrix a input*/
	printf("Enter the elements of 1st matrix:\n");
	int i, j;
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			scanf("%f;", &a[i][j]);
		}
	}
	/*Matrix b input*/
	printf("Enter the elements of 2nd matrix:\n");
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter b%d%d: ", i+1, j+1);
			scanf("%f;", &b[i][j]);
		}
	}
	printf("\nSum of matrices: \n");
	/*Printing the addition of the two matrices.*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%0.1f ", a[i][j] + b[i][j]);
		}
		printf("\n");
	}




	return 0;
}
