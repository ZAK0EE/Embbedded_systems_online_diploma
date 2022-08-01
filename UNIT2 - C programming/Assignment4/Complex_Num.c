#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

struct scomplex
{
	float m_re;
	float m_img;
};

struct scomplex complex_entry()
{
	struct scomplex x;
	printf("Enter real and imaginary respectively: ");
	scanf("%f %f", &x.m_re, &x.m_img);
	return x;
}

struct scomplex complex_add(struct scomplex x1, struct scomplex x2)
{
	struct scomplex result;
	result.m_re = x1.m_re + x2.m_re;
	result.m_img = x1.m_img + x2.m_img;
	return result;
}

int main()
{
	$fix$
	printf("For 1st complex number.\n");
	struct scomplex x1 = complex_entry();	
	
	printf("\nFor 2st complex number.\n");
	struct scomplex x2 = complex_entry();
	
	struct scomplex result = complex_add(x1, x2);
	printf("Sum = %0.1f + i%0.1f\n", result.m_re, result.m_img);
	


	return 0;
}
