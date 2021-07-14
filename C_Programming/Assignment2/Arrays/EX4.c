#include <stdio.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	int a[10], n;
	int i, aindex;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int number, loc;
	printf("Enter the element to be inserted: ");
	scanf("%d", &number);

	printf("Enter the location : ");
	scanf("%d", &loc);
	loc -= 1;
	int newarr[10];
	/*Inserting element*/
	for(i = 0, aindex = 0; i < n + 1; i++)
	{
		if (i == loc)
			newarr[i] = number;
		else
			newarr[i] = a[aindex++];
	}

	printf("Array after insertion: ");
	for(i = 0; i < n + 1; i++)
		printf("%d ", newarr[i]);





	return 0;
}
