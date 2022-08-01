#ifndef SDB_H_
#define SDB_H_
#include <inttypes.h>
typedef struct
{
	char name[40];
	float height;
	uint16_t ID;
}Sdata;

typedef struct SStudent
{
	Sdata data;
	struct SStudent *pNextData;
}SStudent;


uint8_t CreateDataBase(SStudent **pStudent);
uint8_t AddStudent(SStudent **pStudent);
uint8_t DeleteStudent(SStudent **pStudent);
uint8_t DeleteAllStudents(SStudent **pStudent);
SStudent *FindStudent_indx(SStudent **const pStudent, uint16_t index);
uint16_t NumOfStudents(SStudent **pStudent);
void RevAllStudents(SStudent **pStudent);
void PrintStudents(SStudent **const pStudent);

#endif
