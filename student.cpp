//source file for student class, includes definitions

#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#include "student.h"

using namespace std;

//getter functions
int student::getAge() {
	return age;
}
string student::getLastName() {
	return lastName;
}
string student::getFirstName() {
	return firstName;
}
string student::getEmail() {
	return email;
}
string student::getStudentID() {
	return studentID;
}
int* student::getNumberOfDays() {
	return numberOfDays;
}
degreeProgram student::getDegreeProgram() {
	return degree;
}


//setter functions
void student::setAge(int newAge) {
	this->age = newAge;
}
void student::setLastName(string newLastName) {
	this->lastName = newLastName;
}
void student::setFirstName(string newFirstName) {
	this->firstName = newFirstName;
}
void student::setEmail(string newEmail) {
	this->email = newEmail;
}
void student::setStudentID(string newstudentID) {
	this->studentID = newstudentID;
}
void student::setNumberOfDays(int* newNumberOfDays) {
	for (int i = 0; i < daysArraySize; i++) {
		this->numberOfDays[i] = newNumberOfDays[i];
	}
}
void student::setDegreeProgram(degreeProgram newDegreeProgram) {
	this->degree = newDegreeProgram;
}

//print function
void student::print(string printInfo) {
	if (printInfo == "age") {
		cout << "Age: " << this->age << endl;
	}
	else if (printInfo == "lastName") {
		cout << "Last Name: " << this->lastName << endl;
	}
	else if (printInfo == "firstName") {
		cout << "First Name: " << this->firstName << endl;
	}
	else if (printInfo == "email") {
		cout << "Email: " << this->email << endl;
	}
	else if (printInfo == "studentID") {
		cout << "Student ID: " << this->studentID << endl;
	}
	else if (printInfo == "numberOfDays") {
		cout << "Number Of Days to Complete Course: ";
		for (int i = 0; i < daysArraySize; i++) {
			if (i != daysArraySize - 1) {
				cout << this->numberOfDays[i] << ", ";
			}
			else {
				cout << this->numberOfDays[i] << endl;
			}
		}
	}
	else if (printInfo == "degreeProgram") {
		cout << degreeString[(int)degree] << endl;
	}
	else if (printInfo == "All") {

	}
}

//default constructor, constructor and destructor
student::student() {
	this->age = 0;
	this->lastName = "n/a";
	this->firstName = "n/a";
	this->email = "n/a";
	this->studentID = "n/a";
	for (int i = 0; i < daysArraySize; i++) {
		this->numberOfDays[i] = 0;
	}
	this->degree = degreeProgram::None;
}
student::student(int age, string lastName, string FirstName, string email, string studentID, int numberOfDays[], degreeProgram degree) {
	this->age = age;
	this->lastName = lastName;
	this->firstName = firstName;
	this->email = email;
	this->studentID = studentID;
	for (int i = 0; i < daysArraySize; i++) {
		this->numberOfDays[i] = numberOfDays[i];
	}
	this->degree = degree;
}
student::~student() {
	cout << "Student destructor called" << endl;
}

