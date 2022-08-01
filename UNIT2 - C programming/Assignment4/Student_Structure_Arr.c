#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

#define MAX_NAME 50

struct sstudent
{
	char m_name[MAX_NAME];
	float m_mark;
	int m_roll;
};

struct sstudent sstudent_entry()
{
	struct sstudent student;
	printf("Enter name: ");
	scanf("%s", student.m_name);
	
	printf("Enter marks: ");
	scanf("%f", &student.m_mark);
	
	return student;
}

void sstudent_print(struct sstudent student)
{
	printf(
			"Name : %s\n"
			"Marks: %0.2f\n",	student.m_name, student.m_mark
		  );
	return;
}

int main()
{
	$fix$
	struct sstudent student[10];
	printf("Enter information of students:\n\n");
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("For roll number %d.\n", i + 1);
		student[i] = sstudent_entry();
		student[i].m_roll = i + 1;
		printf("\n");
	}
	
	printf("Displaying infomation of students:\n\n");
	for(i = 0; i < 10; i++)
	{
		printf("Information for roll number %d.\n", student[i].m_roll);
		sstudent_print(student[i]);
		printf("\n");
	}	
	
	
	



	return 0;
}
