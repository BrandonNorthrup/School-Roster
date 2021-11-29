/*
Scripting and Programming - Applications - C867
C++
Student ID #001177877
Brandon Northrup
*/

#pragma once
#include "student.h"

class NetworkStudent : public Student {

private:
	Degree degProg = NETWORKING;

public:
	Degree getDegreeProgram() override;

	void Print();

	NetworkStudent();
	NetworkStudent(string, string, string, string, int, int*, Degree);
	//Student(string ID, string First, string Last, string emailAddress, int setAge, int * numDays);
};