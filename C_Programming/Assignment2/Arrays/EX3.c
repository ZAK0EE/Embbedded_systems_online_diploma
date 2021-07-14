#include <stdio.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

void swap(int *a, int *b)
{
	*a = *b + *a;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	$fix$
	int a[10][10], trans[10][10];
	int rows, columns;

	printf("Enter rows and columns of the matrix: ");
	scanf("%d%d", &rows, &columns);
	int i, j;
	/*Matrix a input*/
	printf("Enter elements of matrix: \n");
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			scanf("%d;", &a[i][j]);
		}
	}
	/*Show original matrix*/
	printf("Entered matrix: \n");
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	/*Transpose matrix*/
	for(i = 0; i < rows; i++)
		for(j = 0; j < columns; j++)
			trans[j][i] = a[i][j];

	swap(&rows, &columns);
	/*Show transposed matrix*/
	printf("Transposed matrix: \n");
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf("%d ", trans[i][j]);
		}
		printf("\n");
	}





	return 0;
}
