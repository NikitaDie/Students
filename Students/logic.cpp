#include <iostream>
#include "common.h">

int MAX_ID = 0;

int random(int min = 0, int max = 9)
{
	return rand() % (max - min + 1) + min;
}

std::string randomString(int len = 10)
{
	std::string str;

	char arr[] = "abcdefghujklmnopqrstuvwxyz";

	for (int i{}; i < len; ++i)
		str += arr[random(0, sizeof(arr) - 2)];

	return str;
}

int* generateArr(int count, int min = 0, int max = 9)
{
	int* arr = new int[count];
	for (int i{}; i < count; ++i)
		arr[i] = random(min, max);

	return arr;
}

Student* generateDB(int count, Group* groups, int groupsCount)
{
	Student* arr = new Student[count];

	for (int i{}; i < count; ++i)
	{
		arr[i].id = ++MAX_ID;

		arr[i].f_name = randomString(random(3, 10));
		arr[i].l_name = randomString(random(3, 10));

		arr[i].groupPtr = &groups[random(0, groupsCount - 1)];

		int gCount = random(10, 30);
		arr[i].gradesArr.gCount = gCount;
		arr[i].gradesArr.grades = generateArr(gCount, 1, 12);
	}

	return arr;
}

void renderStudent(const Student* s)
{
	std::cout << "id: " << s->id << '\n';
	std::cout << "name: " << s->f_name << ' ' << s->l_name << '\n';
	std::cout << "group: " << s->groupPtr->title << '\n';

	std::cout << "GRADES:\n";
	for (int i{}; i < s->gradesArr.gCount; ++i)
		std::cout << s->gradesArr.grades[i] << ' ';

	std::cout << "\n-----------------------------\n\n";
}

