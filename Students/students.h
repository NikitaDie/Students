#pragma once
#include "common.h"


int studentsCount = 20;

Student** addStudent(Student** s_arr, int& studentsCount, Group* groups, const int groupsCount, int &MAX_ID);

Student** deleteStudent(Student** s_arr, int& studentsCount, int student_index);