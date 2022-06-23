//source file for student class, includes definitions

#include <iostream>
#include <string>
#include <iomanip>

#include "degree.h"
#include "student.h"

using namespace std;

//getter functions
int Student::getAge() {
	return age;
}
string Student::getLastName() {
	return lastName;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getEmail() {
	return email;
}
string Student::getStudentID() {
	return studentID;
}
int* Student::getNumberOfDays() {
	return numberOfDays;
}
DegreeProgram Student::getDegreeProgram() {
	return degree;
}


//setter functions
void Student::setAge(int newAge) {
	this->age = newAge;
}
void Student::setLastName(string newLastName) {
	this->lastName = newLastName;
}
void Student::setFirstName(string newFirstName) {
	this->firstName = newFirstName;
}
void Student::setEmail(string newEmail) {
	this->email = newEmail;
}
void Student::setStudentID(string newstudentID) {
	this->studentID = newstudentID;
}
void Student::setNumberOfDays(int* newNumberOfDays) {
	for (int i = 0; i < daysArraySize; i++) {
		this->numberOfDays[i] = newNumberOfDays[i];
	}
}
void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {
	this->degree = newDegreeProgram;
}

//print function, input desired print information and outputs
void Student::print(string printInfo) {
	if (printInfo == "age") {
		cout << this->getAge() << "\t"  ;
	}
	else if (printInfo == "lastName") {
		cout << this->getLastName()  << "\t" ;
	}
	else if (printInfo == "firstName") {
		cout << this->getFirstName()  << "\t" ;
	}
	else if (printInfo == "email") {
		cout << this->getEmail()  << "\t" ;
	}
	else if (printInfo == "studentID") {
		cout << this->getStudentID() << "\t" ;
	}
	else if (printInfo == "numberOfDays") {
		for (int i = 0; i < daysArraySize; i++) {
			if (i != daysArraySize - 1) {
				cout << this->getNumberOfDays()[i] << ", ";
			}
			else {
				cout << this->getNumberOfDays()[i] << "\t" ;
			}
		}
	}
	else if (printInfo == "DegreeProgram") {
		cout << degreeString[(int)degree] << "\t" ;
	}
	else if (printInfo == "all") {
		cout << setw(3) << this->getStudentID() << '|';
		cout << setw(10) << this->getFirstName() << '|';
		cout << setw(10) << this->getLastName() << '|';
		cout << setw(25) << this->getEmail() << '|';
		cout << setw(4) << this->getAge() << '|';
		cout << setw(6);
		for (int i = 0; i < daysArraySize; i++) {
			if (i != daysArraySize - 1) {
				cout << this->getNumberOfDays()[i] << ", ";
			}
			else {
				cout << this->getNumberOfDays()[i] << '|';
			}
		}
		cout << setw(10) << degreeString[(int)degree] << '|';
		
	}
	else {
		cout << "Invalid entry for string printInfo parameter." << endl;
	}
}

//default constructor, constructor and destructor
Student::Student() {
	this->age = 0;
	this->lastName = "n/a";
	this->firstName = "n/a";
	this->email = "n/a";
	this->studentID = "n/a";
	for (int i = 0; i < daysArraySize; i++) {
		this->numberOfDays[i] = 0;
	}
	this->degree = DegreeProgram::None;
}
Student::Student(string studentID, string firstName, string lastName, string email, int age, int *numberOfDays, DegreeProgram degree) {
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
Student::~Student() {
	cout << "Student destructor for " << this->studentID << " called." << endl;
}

