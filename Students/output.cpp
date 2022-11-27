#include "common.h"
#include "students.h"

void printLine() {
	std::cout << "\n-----------------------------\n\n";
}

void printGroups(const Group* groups, const int groupsCount)
{
	std::cout << "Groups:";

	for (int i{}; i < groupsCount; ++i) {
		std::cout << "\t" << i + 1 << ": " << groups[i].title << '\n';
	}
	std::cout << "\n";
}


void renderStudent(const Student* s)
{
	std::cout << "id: " << s->id << '\n';
	std::cout << "Name: " << s->f_name << ' ' << s->l_name << '\n';
	std::cout << "Group: " << s->groupPtr->title << '\n';

	std::cout << "GRADES:\n";
	for (int i{}; i < s->gradesArr.gCount; ++i)
		std::cout << s->gradesArr.grades[i] << ' ';

	printLine();
}