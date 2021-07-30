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
	
	printf("Enter roll number: ");
	scanf("%d", &student.m_roll);
	
	printf("Enter marks: ");
	scanf("%f", &student.m_mark);
	
	return student;
}

void sstudent_print(struct sstudent student)
{
	printf("Displaying information:\n"
		   "Name : %s\n"
		   "Roll : %d\n"
		   "Marks: %0.2f\n",	student.m_name, student.m_roll, student.m_mark
		 );
	return;
}

int main()
{
	$fix$
	
	printf("Enter information of students:\n\n");
	struct sstudent student = sstudent_entry();
	printf("\n");
	sstudent_print(student);
	
	
	



	return 0;
}
