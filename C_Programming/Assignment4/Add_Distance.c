#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


struct sdist
{
	int m_feet;
	float m_inches;
};

struct sdist dist_entry()
{
	struct sdist x;
	printf("Enter feet: ");
	scanf("%d", &x.m_feet);
	
	printf("Enter inch: ");
	scanf("%f", &x.m_inches);
	return x;
}

struct sdist dist_add(struct sdist x1, struct sdist x2)
{
	struct sdist result;
	float sum = x1.m_feet * 12.0 + x1.m_inches + x2.m_feet * 12.0 + x2.m_inches; /*Sum of two distances in inches*/
	result.m_feet = sum / 12.0;
	result.m_inches = sum - result.m_feet * 12;
	
	return result;
}
int main()
{
	$fix$
	
	printf("Enter information for 1st distance.\n");
	struct sdist x1 = dist_entry();
	
	printf("\nEnter information for 2st distance.\n");
	struct sdist x2 = dist_entry();
	
	struct sdist result = dist_add(x1, x2);
	printf("Sum of distances: %d'%0.1f\"", result.m_feet, result.m_inches);
	

	return 0;
}
