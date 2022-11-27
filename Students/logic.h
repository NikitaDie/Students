#pragma once
#include "common.h"

Student** generateDB(int count, Group* groups, int groupsCount);

void renderStudent(Student* s);

Student** addStudent(Student** s_arr, int studentsCount, Group* groups, const int groupsCount);