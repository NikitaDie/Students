#include <iostream>
#include "common.h"

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

Student** generateDB(int count, Group* groups, int groupsCount, int &MAX_ID)
{
	Student** arr = new Student*[count];

	for (int i{ 0 }; i < count; ++i)
	{
		arr[i] = new Student;
		arr[i]->id = ++MAX_ID;

		arr[i]->f_name = randomString(random(3, 10));
		arr[i]->l_name = randomString(random(3, 10));

		arr[i]->groupPtr = &groups[random(0, groupsCount - 1)];

		int gCount = random(10, 30);
		arr[i]->gradesArr.gCount = gCount;
		arr[i]->gradesArr.grades = generateArr(gCount, 1, 12);
	}

	return arr;
}


Student** expandArr(Student** s_arr, int& studentsCount) {
	Student** new_arr = new Student*[studentsCount + 1]{ nullptr };
	for (int i{ 0 }; i < studentsCount; ++i)
	{

		new_arr[i] = s_arr[i];
		delete s_arr[i];
	}
	

	new_arr[studentsCount] = new Student;

	delete [] s_arr;

	

	return new_arr;
}

Student** narrowDown(Student** s_arr, int& studentsCount) {
	Student** new_arr = new Student * [studentsCount - 1]{ nullptr };
	for (int i{ 0 }; i < studentsCount; ++i)
	{

		new_arr[i] = s_arr[i];
		delete s_arr[i];
	}


	delete new_arr[studentsCount];
	delete[] s_arr;



	return new_arr;
}

