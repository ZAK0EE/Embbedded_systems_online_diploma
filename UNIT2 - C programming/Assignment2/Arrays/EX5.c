#include <stdio.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int main()
{
	$fix$
	int a[10], n;
	int i;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int number, loc = -1;
	printf("Enter the element to be searched: ");
	scanf("%d", &number);

	for(i = 0; i < n; i++)
		if (a[i] == number)
		{
			loc  = i;
			break;
		}
	if (loc == -1)
		printf("Number not found!");
	else
		printf("Number found at location : %d", loc + 1);








	return 0;
}
