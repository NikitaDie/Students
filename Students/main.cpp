#include <iostream>
#include "common.h"
#include "teacher.h"
#include "groups.h"
#include "students.h"
#include "output.h"
#include "logic.h"

int main()
{
	srand(time(0));
	rand();

	Student** students_arr = generateDB(studentsCount, groups, groupsCount);

	students_arr = addStudent(students_arr, studentsCount, groups, groupsCount);

	renderStudent(students_arr[studentsCount - 1]);

	return 0;
}