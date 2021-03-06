/*
Scripting and Programming - Applications - C867
C++
Student ID #001177877
Brandon Northrup
*/

#include "pch.h"
#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[3];

public:

	// Constructor
	Student();

	// Accessor
	string getStudentID();

	// Mutator
	void setStudentID(string studentID);

	string getFirstName();
	void setFirstName(string firstName);

	string getLastName();
	void setLastName(string lastName);

	string getEmail();
	void setEmail(string email);

	int getAge();
	void setAge(int age);

	int *getDaysInCourse();
	void setDaysInCourse(int course1, int course2, int course3);

	void setDegree(string degree);

	virtual void Print();

	Degree virtual getDegreeProgram();

	Student(string ID, string First, string Last, string emailAddress, int setAge, int * numDays);

	//Destructor
	~Student(); 
};