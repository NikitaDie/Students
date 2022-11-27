#include <iostream>
//#include "common.h"
#include "logic.h"
#include "students.h"
#include "output.h"
#include "groups.h"


int main()
{

	int MAX_ID = 0;
	srand(time(0));
	rand();

	Student** students_arr = generateDB(studentsCount, groups, groupsCount, MAX_ID);

	students_arr = addStudent(students_arr, studentsCount, groups, groupsCount, MAX_ID);

	renderStudent(students_arr[studentsCount - 1]);

	return 0;
}