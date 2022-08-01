#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


int NumSum(int num)
{
	int sum = 0;
	while(num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

double CalcSqr(int num)
{
	return sqrt((double)num);
}

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
void PrintPrime(int n1, int n2)
{
	for(;n1 <= n2; n1++)
		if(IsPrime(n1))
			printf("%d ", n1);
}


int RevNum(int num)
{
	int reverted = 0;
	while (num != 0)
	{
		reverted = reverted * 10 + (num % 10);
		num /= 10;
	}
	return reverted;
}

int CountOnes(int num)
{
	int ones = 0;
	for(;num != 0; num >>= 1)
		ones += num & 1;
	return ones;
}


int Nsum(int length)
{
	return length * (length - 1) / 2;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void RevArr(char arr[], int length)
{
	int i;
	for(i = 0; i < length / 2; i++)
		swap(&arr[i], &arr[length - 1 - i]);
}

void RevWord(char *a, int length)
{
	char *temp = (char*)malloc((length + 1) * sizeof(char));
	int ret = strchr(a, ' ') - a; /*space index*/

	strcpy(temp, &a[ret + 1]);
	strcat(temp, " ");
	strncat(temp, a, ret);
	/*Cpying back in the original string*/
	strcpy(a, temp);
	free(temp);



}
int CountM1B0(int n)
{
	int a, max, count;
	max = count = 0;
	for(; n != 0; n >>= 1)
	{
		a = n & 1;
		if(a == 1)
			count++;
		else
		{
			if (count > max)
				max = count;
			count = 0;
		}
	}
	if (count > max)
		max = count;
	return max;
}
int main()
{
	$fix$
	int count = 2;
	int num;
	while (count--)
	{
		printf("input: ");
		scanf("%d", &num);
		printf("output: %d\n", CountM1B0(num));

	}

	return 0;
}

