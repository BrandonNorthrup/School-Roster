/*
Scripting and Programming - Applications - C867
C++
Student ID #001177877
Brandon Northrup
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include "roster.h"

using namespace std;

Roster::Roster() {}


int main() {

	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Created using C++" << endl;
	cout << "Student ID #001177877" << endl;
	cout << "Brandon Northrup" << endl;

	string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Brandon,Northrup,bnort12@wgu.edu,25,7,14,3,SOFTWARE,"
	};

	Roster classRoster;

	Degree degreeObject;

	int i = 0;

	for (i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {

		string input = studentData[i];
		istringstream ss(input);
		string token;
		string holderArray[9];

		int x = 0;
		while (getline(ss, token, ',')) {
			holderArray[x] = token;
			x += 1;
		}

		if (holderArray[8] == "SECURITY") {
			degreeObject = Degree::SECURITY;
		}

		else if (holderArray[8] == "SOFTWARE") {
			degreeObject = Degree::SOFTWARE;
		}

		else if (holderArray[8] == "NETWORK") {
			degreeObject = Degree::NETWORKING;
		}

		classRoster.Add(holderArray[0], holderArray[1], holderArray[2], holderArray[3], stoi(holderArray[4]), stoi(holderArray[5]),
			stoi(holderArray[6]), stoi(holderArray[7]), degreeObject);
	}

	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();

	for (i = 0; i < 5; i++) {
		classRoster.PrintAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
	}

	cout << endl;
	classRoster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.Remove("A3");
	classRoster.Remove("A3");

	system("pause");
}


// Update classRosterArray
void Roster::Add(string ID, string First, string Last, string emailAddress, int setAge, int numDays0, int numDays1, int numDays2, Degree degProg) {

	int averageDaysInCourse[3] = { numDays0, numDays1, numDays2 };

	if (degProg == NETWORKING) {
		classRosterArray[globalClassIndex] = new NetworkStudent(ID, First, Last, emailAddress, setAge, averageDaysInCourse, degProg);
	}

	else if (degProg == SECURITY) {
		classRosterArray[globalClassIndex] = new SecurityStudent(ID, First, Last, emailAddress, setAge, averageDaysInCourse, degProg);
	}

	else if (degProg == SOFTWARE) {
		classRosterArray[globalClassIndex] = new SoftwareStudent(ID, First, Last, emailAddress, setAge, averageDaysInCourse, degProg);
	}

	globalClassIndex = globalClassIndex + 1;
}


// Find studentID in roster array
void Roster::Remove(string studentID) {

	bool boolRemove = false;
	int i = 0;

	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && (*classRosterArray[i]).getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			boolRemove = true;
			break;
		}
	}

	if (boolRemove == false) {
		cout << "ERROR! Student ID: " << studentID << " not found. Deleting ID..." << endl << endl;
	}
}


// Print whole roster
void Roster::PrintAll() {

	cout << endl << "Show All" << endl << endl;

	int i;
	for (i = 0; i < 5; i++) {
		(*classRosterArray[i]).Print();
	}
	cout << endl;
}


// Add number of days in all 3 courses and print the average
void Roster::PrintAverageDaysInCourse(string studentID) {

	float averageDaysInCourse = 0;
	int maximumValue = 3;

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			int *daysInCourse = classRosterArray[i]->getDaysInCourse();
			for (int x = 0; x < maximumValue; x++) {
				averageDaysInCourse += daysInCourse[x];
			}

			cout << "Student " << classRosterArray[i]->getStudentID() << " was in each course for an average of " << (averageDaysInCourse / maximumValue) << " days." << endl;
			break;
		}
	}
}


// Print any emails that are in an invalid format
void Roster::PrintInvalidEmails() {

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {

		string invalidEmails = classRosterArray[i]->getEmail();
		int npos = -1;

		if ((invalidEmails.find("@") == npos) || (invalidEmails.find(".") == npos) || !(invalidEmails.find(" ") == npos)) {
			cout << invalidEmails << " is an invalid email address" << endl;
		}
	}
	cout << endl;
}


// Filter students by their degree
void Roster::PrintByDegreeProgram(Degree degreeProgram) {

	cout << "Filtered By Degree Program:" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}


Student** Roster::getClassRosterArray() {

	return classRosterArray;
}


Roster::~Roster() {

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}