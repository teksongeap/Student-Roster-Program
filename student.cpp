//source file for Student class, includes implementations
#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#include "student.h"

using namespace std;

//getter functions
int Student::getAge() const {
	return age;
}
string Student::getLastName() const {
	return lastName;
}
string Student::getFirstName() const {
	return firstName;
}
string Student::getEmail() const {
	return email;
}
string Student::getStudentID() const {
	return studentID;
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
void Student::setStudentID(string newStudentID) {
	this->studentID = newStudentID;
}

Book::Book()