#pragma once
#include "common.h"
#include "groups.h"
#include "students.h"

void printLine();

void printGroups(const Group* groups, const int groupsCount);

void renderStudent(const Student* s);