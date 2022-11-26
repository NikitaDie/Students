#include <iostream>
#include <iostream>
#include "common.h"
#include "logic.h"

int main()
{
	srand(time(0));
	rand();

	Teacher t1{ "Brus", "Willis" };
	Teacher t2{ "Chack", "Norris" };
	Teacher t3{ "Jackie", "Chan" };

	int groupsCount = 7;
	Group* groups = new Group[groupsCount]{
		{"P10", &t2},
		{"P11", &t2},
		{"P12", &t2},
		{"P13", &t1},
		{"P14", &t1},
		{"P15", &t3},
		{"P16", &t3},
	};

	int studentsCount = 20;
	Student* arr = generateDB(studentsCount, groups, groupsCount);

	for (int i{}; i < studentsCount; ++i)
		renderStudent(&arr[i]);




	return 0;
}