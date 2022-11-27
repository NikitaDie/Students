#pragma once
#include <iostream>
struct Teacher
{
	std::string f_name{ "no_f_name" };
	std::string l_name{ "no_l_name" };
};

struct Group
{
	std::string title{ "no_title" };
	Teacher* teacher{ nullptr };
};

struct GradesArr
{
	int* grades{ nullptr };
	int gCount{ 0 };
};

struct Student
{
	int id{ -1 };
	std::string f_name{ "no_f_name" };
	std::string l_name{ "no_l_name" };
	Group* groupPtr{ nullptr };
	GradesArr gradesArr{};
};
