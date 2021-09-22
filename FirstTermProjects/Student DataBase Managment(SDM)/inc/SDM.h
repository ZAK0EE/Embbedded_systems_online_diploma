/*
 * SDM.h
 * This file was created by Eng.Ziad Ashraf
 * For course learn-in-depth project by Eng.Kerlos
 * On 22/09/2021
 */

#ifndef INC_SDM_H_
#define INC_SDM_H_

/*Student info*/
typedef struct
{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
}SStudent;

/*Shows all the available options for the user[The project interface]*/
void SDM_MenuScreen();

/*Add student manually*/
void SDM_AddStudent(Queue *DataBase);
/*Add student from a text file using \t as a delimiter -Each line reassembles a student-*/
void SDM_FAddStudent(Queue *DataBase, char filename[]);
/*Modify student data using his roll number*/
int SDM_UpdateStudent(Queue *DataBase, int roll);
/*Delete specific student using roll number*/
void SDM_DeleteStudent(Queue *DataBase, int roll);

/*Check if the roll number already exists*/
int SDM_IsRollExist(Queue *DataBase, int roll);

/*Print Student*/
void SDM_PrintStudent(SStudent *student);
/*Search and print student using Roll number*/
void SDM_PrintStudent_Roll(Queue *DataBase, int roll);
/*Search and print student using First name*/
void SDM_PrintStudent_Fname(Queue *DataBase, char fname[]);
/*Search and print students who are participated in specific course*/
void SDM_PrintStudent_Cid(Queue *DataBase, int cid);

/*Save all students in file*/
void SDM_SaveStudents(Queue *DataBase, char filename[]);




#endif /* INC_SDM_H_ */
