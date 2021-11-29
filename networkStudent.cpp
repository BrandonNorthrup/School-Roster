/*
Scripting and Programming - Applications - C867
C++
Student ID #001177877
Brandon Northrup
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "networkStudent.h"

NetworkStudent::NetworkStudent() {

}

NetworkStudent::NetworkStudent(string ID, string First, string Last, string emailAddress, int setAge, int *numDays, Degree studentDegree) : Student(ID, First, Last, emailAddress, setAge, numDays) {

	degProg = studentDegree;
}

Degree NetworkStudent::getDegreeProgram() {

	return degProg;
}

void NetworkStudent::Print() {

	cout << getStudentID();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Age: " << getAge();
	cout << "\t" << "Days In Course: {"; cout << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "}";
	cout << "\t Degree Program: NETWORK";
	cout << endl;
}