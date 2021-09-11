#include "SDB.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint8_t CreateDataBase(SStudent **pStudent)
{
	*pStudent = NULL;
	return 1;
}
uint8_t AddStudent(SStudent **pStudent)
{
	SStudent *FinalStudent = *pStudent;
	SStudent *NewStudent = NULL;
	char buff[40];

	/*Checking if this is the first student*/
	if(FinalStudent == NULL)
	{
		NewStudent = (SStudent *)malloc(sizeof(SStudent));
		*pStudent = NewStudent;
	}
	else
	{
		/*Iterating to final student*/
		while(FinalStudent->pNextData != NULL)
			FinalStudent = FinalStudent->pNextData;
		NewStudent = (SStudent *)malloc(sizeof(SStudent));
		FinalStudent->pNextData = NewStudent;

	}

	/*Student information entry*/
	printf("Enter the ID: ");
	gets(buff);
	NewStudent->data.ID = atoi(buff);

	printf("Enter the student full name: ");
	gets(NewStudent->data.name);


	printf("Enter the height: ");
	gets(buff);
	NewStudent->data.height = atof(buff);

	NewStudent->pNextData = NULL;
	return 1;
}

uint8_t DeleteStudent(SStudent **pStudent)
{
	char buff[40];
	uint16_t id;

	printf("Enter the student id to be deleted: ");
	gets(buff);
	id = atoi(buff);

	/*If list is not empty*/
	if(!pStudent)
		return 0;

	SStudent *CurrentStudent = NULL;
	SStudent *PreviousStudent = NULL;

	CurrentStudent = *pStudent;
	PreviousStudent = NULL;
	/*If first student ID matches the required id*/
	if(CurrentStudent->data.ID == id)
	{
		*pStudent = CurrentStudent->pNextData;
		free(CurrentStudent);
		return 1;
	}
	/*Iterate over students until you find the required id*/
	while(CurrentStudent->data.ID != id && CurrentStudent != NULL)
	{
		PreviousStudent = CurrentStudent;
		CurrentStudent = CurrentStudent->pNextData;

	}
	if(CurrentStudent == NULL)
	{
		return 0;
	}
	PreviousStudent->pNextData = CurrentStudent->pNextData;
	free(CurrentStudent);
	return 1;


}

uint8_t DeleteAllStudents(SStudent **pStudent)
{
	if(*pStudent == NULL)
		return 0;

	SStudent *CurrentStudent = NULL;
	SStudent *PreviousStudent = NULL;

	CurrentStudent = *pStudent;
	PreviousStudent = NULL;
	while(CurrentStudent != NULL)
	{
		free(PreviousStudent);
		CurrentStudent = CurrentStudent->pNextData;
	}
	*pStudent = NULL;
	return 1;


}
SStudent *FindStudent_indx(SStudent **const pStudent, uint16_t index)
{
	SStudent *CurrentStudent = *pStudent;
	while(index--)
	{
		CurrentStudent = CurrentStudent->pNextData;
	}
	return CurrentStudent;
}

uint16_t NumOfStudents(SStudent **const pStudent)
{
	uint16_t count = 0;
	SStudent *CurrentStudent = *pStudent;
	while(CurrentStudent != NULL)
	{
		CurrentStudent = CurrentStudent->pNextData;
		count++;
	}
	return count;

}

void RevAllStudents(SStudent **pStudent)
{
	SStudent *CurrentStudent = *pStudent;
	SStudent *temp = NULL;
	SStudent *PreviousStudent = NULL;
	while(CurrentStudent != NULL)
	{
		temp = CurrentStudent;
		CurrentStudent = CurrentStudent->pNextData;
		temp->pNextData = PreviousStudent;
		PreviousStudent = temp;
	}
	*pStudent = temp;

}
void PrintStudents(SStudent **const pStudent)
{
	SStudent *CurrentStudent = *pStudent;
	printf("Database students:\n");
	uint16_t index = 0;
	while(CurrentStudent != NULL)
	{
		printf("\tIndex: %d\n", index);
		printf("\tStudent id: %d\n", CurrentStudent->data.ID);
		printf("\tStudent name: %s\n", CurrentStudent->data.name);
		printf("\tStudent height: %0.0f\n", CurrentStudent->data.height);
		printf("\t*********************\n");
		CurrentStudent = CurrentStudent->pNextData;
		index++;
	}

}
