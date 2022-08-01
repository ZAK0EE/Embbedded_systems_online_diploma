#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
# define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

#define MIN(x, y) ((x) < (y) ? (x) : (y))
int main()
{
	$fix$
	int n;
	int arr[15];
	printf("Input the number of elements to store in the array (max 15) : ");
	scanf("%d", &n);
	n = MIN(n, 15);
	int i = 0;
	/*Input loop*/
	for (i = 0; i < n; i++)
	{
		printf("element -%d : ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("The elements of array in reverse order are :\n");
	/*Reverse loop*/
	int *pint = arr + n - 1;
	for (i = n - 1; i >= 0; i--)
	{
		printf("element - %d : %d\n", i + 1, *pint);
		pint--;
	}
	return 0;

}
