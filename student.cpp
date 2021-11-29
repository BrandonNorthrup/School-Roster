/*
Scripting and Programming - Applications - C867
C++
Student ID #001177877
Brandon Northrup
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "student.h"

using namespace std;


// Default Constructor
Student::Student() {

}


// Constructor with parameters
Student::Student(string ID, string First, string Last, string emailAddress, int setAge, int* numDays) {

	studentID = ID;
	firstName = First;
	lastName = Last;
	email = emailAddress;
	age = setAge;
	daysInCourse[0] = numDays[0];
	daysInCourse[1] = numDays[1];
	daysInCourse[2] = numDays[2];
}


string Student::getStudentID() {
	return studentID;
}


void Student::setStudentID(string ID) {
	this->studentID = ID;
}


string Student::getFirstName() {
	return firstName;
}


void Student::setFirstName(string First) {
	this->firstName = First;
}


string Student::getLastName() {
	return lastName;
}


void Student::setLastName(string Last) {
	this->lastName = Last;
}


string Student::getEmail() {
	return email;
}


void Student::setEmail(string emailAddress) {
	this->email = emailAddress;
}


int Student::getAge() {
	return age;
}


void Student::setAge(int setAge) {
	this->age = setAge;
}


int * Student::getDaysInCourse() {
	return daysInCourse;
}


void Student::setDaysInCourse(int numDays0, int numDays1, int numDays2) {
	this->daysInCourse[0] = numDays0;
	this->daysInCourse[1] = numDays1;
	this->daysInCourse[2] = numDays2;
}


void Student::setDegree(string degree) {
	degree = degree;
}


Degree Student::getDegreeProgram() {
	return Degree::SOFTWARE;
}


void Student::Print() {

}


// Destructor
Student::~Student() {

}