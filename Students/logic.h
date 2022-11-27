#pragma once
#include "common.h"


Student** generateDB(int count, Group* groups, int groupsCount);

Student** expandArr(Student** s_arr, int& studentsCount);

Student** narrowDown(Student** s_arr, int& studentsCount);