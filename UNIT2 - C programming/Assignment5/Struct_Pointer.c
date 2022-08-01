#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
# define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

struct SEmployee
{
	char m_name[50];
	int m_id;
};
void SEmployee_Print(struct SEmployee *Pemp)
{
	printf("Employee Name : %s\n", Pemp->m_name);
	printf("Employee ID   : %d\n", Pemp->m_id);
}
int main()
{
	$fix$
	struct SEmployee x = {"Alex", 1002};
	SEmployee_Print(&x);
	return 0;

}
