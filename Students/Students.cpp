#include <iostream>
#include "common.h"
#include "students.h"
#include "output.h"
#include "logic.h"

Student** addStudent(Student** s_arr, int& studentsCount, Group* groups, const int groupsCount)
{

	s_arr = expandArr(s_arr, studentsCount);

	int group;
	s_arr[studentsCount]->id = ++MAX_ID;

	std::cout << "New Student:" << "\n\n";

	std::cout << "Firts Name: ";
	std::cin >> s_arr[studentsCount]->f_name;

	std::cout << "Last Name: ";
	std::cin >> s_arr[studentsCount]->l_name;

	std::cout << "id: " << s_arr[studentsCount]->id << '\n';

	printGroups(groups, groupsCount);
	std::cout << "Choose the group: ";
	std::cin >> group;

	s_arr[studentsCount]->groupPtr = &groups[group - 1];

	std::cout << "\nThe student were added...";

	printLine();

	studentsCount++;

	return s_arr;
}

Student** deleteStudent(Student** s_arr, int& studentsCount, int student_index)
{
	std::cout << "\nThe student" << s_arr[student_index]->id << ", " << s_arr[student_index]->l_name << s_arr[student_index]->f_name << "were deleted...";

	s_arr = narrowDown(s_arr, studentsCount);

	printLine();

	studentsCount--;

	return s_arr;
}