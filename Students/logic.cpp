#include <iostream>
#include "common.h">

int MAX_ID = 0;

void printLine() {
	std::cout << "\n-----------------------------\n\n";
}

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

Student** generateDB(int count, Group* groups, int groupsCount)
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

void printGroups(const Group* groups, const int groupsCount)
{
	std::cout << "Groups:";

	for (int i{}; i < groupsCount; ++i) {
		std::cout << "\t" << i + 1 << ": " << groups[i].title << '\n';
	}
	std::cout << "\n";
}


void renderStudent(Student* s)
{
	std::cout << s;
	std::cout << "id: " << s->id << '\n';
	std::cout << "name: " << s->f_name << ' ' << s->l_name << '\n';
	std::cout << "group: " << s->groupPtr->title << ',';

	std::cout << "GRADES:\n";
	for (int i{}; i < s->gradesArr.gCount; ++i)
		std::cout << s->gradesArr.grades[i] << ' ';

	printLine();
}


Student** expandArr(Student** s_arr, int studentsCount) {
	Student** new_arr = new Student*[studentsCount + 1]{ nullptr };
	for (int i{ 0 }; i < studentsCount; ++i)
	{
		//new_arr[i] = new Student;
		new_arr[i] = s_arr[i];
		delete s_arr[i];
	}
	
	new_arr[studentsCount + 1] = new Student;

	delete [] s_arr;

	return new_arr;
}

Student** addStudent(Student** s_arr, int studentsCount, Group* groups, const int groupsCount)
{

	s_arr = expandArr(s_arr, studentsCount);

	int group;
	s_arr[studentsCount + 1]->id = ++MAX_ID;

	std::cout << "New Student:" << "\n\n";

	std::cout << "Firts Name: ";
	std::cin >> s_arr[studentsCount + 1]->f_name;

	std::cout << "Last Name: ";
	std::cin >> s_arr[studentsCount + 1]->l_name;

	std::cout << "id: " << s_arr[studentsCount + 1]->id << '\n';

	printGroups(groups, groupsCount);
	std::cout << "Choose the group: ";
	std::cin >> group;
	
	printLine();

	return s_arr;
}