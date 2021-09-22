#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
#include "SDM.h"

#define MAX_COURSE 5

void SDM_MenuScreen()
{
	Queue DataBase;
	QueueCreate(&DataBase);
	printf("\t***Welcome to Student DataBase Management system***\n");
	while(1)
	{
		int choice, roll, courseID;
		char buff [50];
		do
		{
			printf("Choose the task you want to perform:\n");
			printf("1. Add the student details manually.\n");
			printf("2. Add the students details from a file.\n");
			printf("3. Update student details using roll number.\n");
			printf("4. Find student details using roll number.\n");
			printf("5. Find student details using first name.\n");
			printf("6. Find students participated in specific course.\n");
			printf("7. Find total number of students.\n");
			printf("8. Delete student details using roll number.\n");
			printf("9. Show all students information.\n");
			printf("10.Exit.\n");
			printf("You choice is : ");
			scanf("%d", &choice);
		}
		while(choice < 1 || choice > 10);
		printf("\n\n");
		switch(choice)
		{
		case 1:
			SDM_AddStudent(&DataBase);
			break;
		case 2:
			printf("Enter the file name: ");
			scanf("%s", buff);
			SDM_FAddStudent(&DataBase, buff);
			break;
		case 3:
			printf("Enter the roll number: ");
			scanf("%d", &roll);
			SDM_UpdateStudent(&DataBase, roll);
			break;
		case 4:
			printf("Enter the roll number: ");
			scanf("%d", &roll);
			SDM_PrintStudent_Roll(&DataBase, roll);
			break;
		case 5:
			printf("Enter first name : ");
			scanf("%s", buff);
			SDM_PrintStudent_Fname(&DataBase, buff);
			break;
		case 6:
			printf("Enter the course ID: ");
			scanf("%d", &courseID);
			SDM_PrintStudent_Cid(&DataBase, courseID);
			break;
		case 7:
			printf("[INFO]Total number of students is: %d\n", DataBase.size);
			break;
		case 8:
			printf("Enter the roll number: ");
			scanf("%d", &roll);
			SDM_DeleteStudent(&DataBase, roll);
			break;
		case 9:
			TraverseQueue(&DataBase, (void*)&SDM_PrintStudent);
			break;
		case 10:
			printf("[INFO]Saving Data -Please don't turn off the program-.\n");
			SDM_SaveStudents(&DataBase, "SDM.txt");
			return ;
			break;

		}

		printf("\n\n\n\n");

	}
}

void SDM_AddStudent(Queue *DataBase)
{
	SStudent temp;
	printf("Enter the roll number: ");
	scanf("%d", &temp.roll);
	if(SDM_IsRollExist(DataBase, temp.roll))
	{
		printf("[ERROR]Roll number already exists\n");
		return;
	}

	printf("Enter the first name: ");
	scanf("%s", temp.fname);

	printf("Enter the last name: ");
	scanf("%s", temp.lname);

	printf("Enter the GPA: ");
	scanf("%f", &temp.GPA);

	printf("Enter the course id of each course: \n");
	int i;
	for(i = 0; i < MAX_COURSE; i++)
	{
		printf("Course %d ID is: ", i + 1);
		scanf("%d", &temp.cid[i]);
	}
	QueueAppend(DataBase, &temp, sizeof(SStudent));
	printf("[INFO]Total number of student is: %d\n", DataBase->size);
}

void SDM_FAddStudent(Queue *DataBase, char filename[])
{
	FILE *input = fopen(filename, "r");
	if(input == NULL)
	{
		printf("[ERROR]File does not exist\n");
		return;
	}
	/*Reading line by line and appending to the database*/
	SStudent temp;
	int lines = 0;
	while(fscanf(input, "%d\t%s\t%s\t%f\t%d\t%d\t%d\t%d\t%d", &temp.roll, temp.fname, temp.lname, &temp.GPA, &temp.cid[0], &temp.cid[1], &temp.cid[2], &temp.cid[3], &temp.cid[4]) != EOF)
	{

		if(!SDM_IsRollExist(DataBase, temp.roll))
		{
			QueueAppend(DataBase, &temp, sizeof(SStudent));
			printf("[INFO]Roll number %d is Added successfully\n", temp.roll);
		}

		else
			printf("[ERROR]Duplicate student roll number on line %d\n", lines + 1);
		lines++;
	}
	fclose(input);

}

int SDM_UpdateStudent(Queue *DataBase, int roll)
{
	QueueNode *node = DataBase->front;
	while(node != NULL)
	{
		if( ((SStudent*)(node->entry))->roll == roll)
		{
			SDM_PrintStudent(node->entry);
			int choice;
			do
			{
				printf("Enter the number of what you want to change: \n");
				printf("1- Roll Number\n");
				printf("2- First Name\n");
				printf("3- Last Name\n");
				printf("4- GPA\n");
				printf("5- CourseID\n");
				printf("Choice: ");
				scanf("%d", &choice);
			}
			while(choice < 1 || choice > 5);
			printf("\n\n");
			int courseID = -1, i;
			switch(choice)
			{
			case 1:
				printf("Enter the new Roll number : ");
				scanf("%d", &((SStudent*)(node->entry))->roll);
				break;
			case 2:
				printf("Enter the new First Name : ");
				scanf("%s", ((SStudent*)(node->entry))->fname);
				break;
			case 3:
				printf("Enter the new Last Name : ");
				scanf("%s", ((SStudent*)(node->entry))->lname);
				break;
			case 4:
				printf("Enter the new GPA number : ");
				scanf("%f", &((SStudent*)(node->entry))->GPA);
				break;
			case 5:
				printf("Enter which course ID you want to change: ");
				scanf("%d", &courseID);
				for(i = 0; i < MAX_COURSE; i++)
				{
					if(((SStudent*)(node->entry))->cid[i] == courseID)
					{
						printf("Enter the new course ID: ");
						scanf("%d", &((SStudent*)(node->entry))->cid[i]);
					}
				}
			}

			return 1;
		}

		node = node->next;
	}
	return 0;
}

void SDM_DeleteStudent(Queue *DataBase, int roll)
{
	int found = 0;
	QueueNode *Current = DataBase->front;
	QueueNode *Last = NULL;
	/*In case the roll matches the first student in the queue*/
	if(((SStudent*)(Current->entry))->roll == roll)
	{
		DataBase->front = DataBase->front->next;
		free(Current);
		return;
	}
	while(Current != NULL)
	{
		if( ((SStudent*)(Current->entry))->roll == roll)
		{
			found = 1;
			/*Delete student*/
			Last->next = Current->next;
			free(Current);
			DataBase->size--;
			break;

		}
		Last = Current;
		Current = Current->next;
	}
	if(found == 0)
		printf("[ERROR]Student could not be found!\n");
	return;
}

int SDM_IsRollExist(Queue *DataBase, int roll)
{
	QueueNode *node = DataBase->front;
	while(node != NULL)
	{
		if( ((SStudent*)(node->entry))->roll == roll)
			return 1;
		node = node->next;
	}
	return 0;

}

void SDM_PrintStudent(SStudent *student)
{
	printf("Student roll: %d\n", student->roll);
	printf("Student First name: %s\n", student->fname);
	printf("Student Last name: %s\n", student->lname);
	printf("Student GPA : %0.1f\n", student->GPA);
	printf("Student Courses IDs: \n");
	int i;
	for(i = 0; i < MAX_COURSE; i++)
	{
		printf("Course %d ID is: %d\n", i + 1, student->cid[i]);
	}
	printf("*****************************\n");

}

void SDM_PrintStudent_Roll(Queue *DataBase, int roll)
{
	int found = 0;
	QueueNode *node = DataBase->front;
	while(node != NULL)
	{
		if( ((SStudent*)(node->entry))->roll == roll)
		{
			found = 1;
			SDM_PrintStudent(node->entry);
			return;
		}
		node = node->next;
	}
	if(found == 0)
		printf("[ERROR]Student could not be found!\n");
	return;
}

void SDM_PrintStudent_Fname(Queue *DataBase, char fname[])
{
	int found = 0;
	QueueNode *node = DataBase->front;
	while(node != NULL)
	{
		if( strcmp( ((SStudent*)(node->entry))->fname , fname) == 0)
		{
			found = 1;
			SDM_PrintStudent(node->entry);
		}
		node = node->next;
	}
	if(found == 0)
		printf("[ERROR]Student could not be found!\n");
	return;
}

void SDM_PrintStudent_Cid(Queue *DataBase, int cid)
{
	int found = 0;
	QueueNode *node = DataBase->front;
	while(node != NULL)
	{
		for(int i = 0; i < MAX_COURSE; i++)
		{
			if( ((SStudent*)(node->entry))->cid[i] == cid)
			{
				found = 1;
				SDM_PrintStudent(node->entry);
			}
		}

		node = node->next;
	}
	if(found == 0)
		printf("[ERROR]Student could not be found!\n");
	return;
}

void SDM_SaveStudents(Queue *DataBase, char filename[])
{
	FILE *output = fopen(filename, "w");

	SStudent *student = (SStudent*)malloc(sizeof(SStudent));
	while(DataBase->size != 0)
	{
		QueueServe(DataBase, (void**)&student, sizeof(SStudent));
		fprintf(output, "%d\t%s\t%s\t%0.1f\t%d\t%d\t%d\t%d\t%d\n", student->roll, student->fname, student->lname, student->GPA, student->cid[0], student->cid[1], student->cid[2], student->cid[3], student->cid[4]);
	}
	free(student);
	fclose(output);
	printf("[INFO]All students are saved successfully!\n");


}

