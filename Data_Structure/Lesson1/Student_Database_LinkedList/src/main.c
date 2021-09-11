#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "SDB.h"


#define $fix$ setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

void printStudent(SStudent *student)
{
	printf("\tStudent id: %d\n", student->data.ID);
	printf("\tStudent name: %s\n", student->data.name);
	printf("\tStudent height: %0.0f\n", student->data.height);
	printf("\t*********************\n");

}
int main()
{
	$fix$
	char buff[100];
	uint16_t choice;
	SStudent *DataBase;
	SStudent *temp;
	CreateDataBase(&DataBase);

	while(1)
	{

		printf("********Student Database Management********\n");
		printf("Please pick any of available options below:\n");
		printf("\t1-Add Student.\n");
		printf("\t2-Find Student.\n");
		printf("\t3-Delete Student.\n");
		printf("\t4-Delete All Students.\n");
		printf("\t5-Number of students.\n");
		printf("\t6-Print all students.\n");
		printf("\t7-Reverse the students list.\n");
		printf("Choice: ");
		gets(buff);
		choice = atoi(buff);
		printf("\n\n");
		switch(choice)
		{
		case 1:
			AddStudent(&DataBase);
			break;
		case 2:
			printf("Enter the index: ");
			gets(buff);
			choice = atoi(buff);
			temp = FindStudent_indx(&DataBase, choice);
			printStudent(temp);
			break;
		case 3:
			DeleteStudent(&DataBase);
			break;
		case 4:
			DeleteAllStudents(&DataBase);
			break;
		case 5:
			choice = NumOfStudents(&DataBase);
			printf("Number of students is: %d", choice);
			break;
		case 6:
			PrintStudents(&DataBase);
			break;
		case 7:
			RevAllStudents(&DataBase);
		}
		printf("\n\n");
	}


	return 0;
}
