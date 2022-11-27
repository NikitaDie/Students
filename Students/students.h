#pragma once
#include "common.h"
#include "groups.h"

struct Student
{
	int id{ -1 };
	std::string f_name{ "no_f_name" };
	std::string l_name{ "no_l_name" };
	Group* groupPtr{ nullptr };
	GradesArr gradesArr{};
};


int studentsCount = 20;

Student** addStudent(Student** s_arr, int& studentsCount, Group* groups, const int groupsCount);

Student** deleteStudent(Student** s_arr, int& studentsCount, int student_index);