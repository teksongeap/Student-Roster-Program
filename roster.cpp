//source file for Roster class, includes definitions

#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

//parses string by comma into viable arguments for add() function, done with find() and substr()
void Roster::parse(string studentInfo) {
	//all arguments pertaining to student to be extracted
	string studID, fName, lName, email;
	int age, days1, days2, days3;
	string degreeString; //used to avoid trying to convert string to enum
	DegreeProgram degree = DegreeProgram::None;


	//a total of 9 arguments to be extracted, to be incremented in while loop
	int nextArg = 1; 

	//first argument extracted (student ID)
	int rightSide = studentInfo.find(",");
	int leftSide = 0;
	studID = studentInfo.substr(leftSide, rightSide);
	nextArg++;

	while (nextArg <= 9) {
		leftSide = rightSide + 1;
		
		if (nextArg == 2) { //if statement for first name
			rightSide = studentInfo.find(",", leftSide);
			fName = studentInfo.substr(leftSide, rightSide - leftSide);
		}
		else if (nextArg == 3) { //if statement for last name
			rightSide = studentInfo.find(",", leftSide);
			lName = studentInfo.substr(leftSide, rightSide - leftSide);
		}
		else if (nextArg == 4) { //if statement for email
			rightSide = studentInfo.find(",", leftSide);
			email = studentInfo.substr(leftSide, rightSide - leftSide);
		}
		else if (nextArg == 5) { //if statement for age, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			age = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
		}
		else if (nextArg == 6) { //if statement for days1, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			days1 = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
		}
		else if (nextArg == 7) { //if statement for days2, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			days2 = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
		}
		else if (nextArg == 8) { //if statement for days3, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			days3 = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
		}
		else if (nextArg == 9) { //if statement for degree program, grabs last substr and uses it to determine degree
			degreeString = studentInfo.substr(leftSide);
			if (degreeString == "SECURITY") {
				degree = DegreeProgram::Security;
			}
			else if (degreeString == "NETWORK") {
				degree = DegreeProgram::Network;
			}
			else if (degreeString == "SOFTWARE") {
				degree = DegreeProgram::Software;
			}
		}

		//increments nextArg so while loop can progress through switch
		nextArg++;
	}

	add(studID, fName, lName, email, age, days1, days2, days3, degree);
}

//adds Student object to studentRoster based on arguments passed after being parsed
void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degree) 
{
	//packs the three integers above into an array
	int daysArr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	//Student is added to the roster
	studentRoster[++lastIndex] = new Student(
		studentID, firstName, lastName, emailAddress, age, daysArr, degree);
}

//removes Student from studentRoster based on studentID
void Roster::remove(string studentID) {
	cout << "Attempting to remove Student " << studentID << "..." << endl << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRoster[i]->getStudentID() == "--") {
			cout << "Student not found!" << endl << endl;
		}
		else if (Roster::studentRoster[i]->getStudentID() == studentID) {
			int placeHolder[] = { 0, 0, 0 };
			Roster::studentRoster[i]->setStudentID("--");
			Roster::studentRoster[i]->setFirstName("----------");
			Roster::studentRoster[i]->setLastName("----------");
			Roster::studentRoster[i]->setEmail("---------REMOVED---------");
			Roster::studentRoster[i]->setNumberOfDays(placeHolder);
			Roster::studentRoster[i]->setAge(0);
			Roster::studentRoster[i]->setDegreeProgram(DegreeProgram::None);
			cout << "Removed student " << studentID << "." << endl << endl;
			break;
		}
	}
}

//prints all information from studentRoster tabulated to look nice
void Roster::printAll() {
	//header of table
	cout << "Format: Student ID | First Name | Last Name | Email | Age | Days In Course | Degree" << endl << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
			studentRoster[i]->print("all");
			cout << endl;
	}
	cout << endl;
}

//prints average days in course for Student object based on studentID
void Roster::printAverageDaysInCourse(string studentID) {
	cout << "Average days in course for Student " << studentID << ": ";
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRoster[i]->getStudentID() == studentID) {
			int total = 0;
			for (int j = 0; j < 3; j++){ 
				total += Roster::studentRoster[i]->getNumberOfDays()[j];
			}
			cout << total / 3.0 << endl << endl;
		}
	}
}

//prints invalid emails from studentRoster
//criteria: a valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
	cout << "Invalid Emails:" << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		//if find() returns position for ' ', OR does not return position for '@' or '.', email is invalid
		if (Roster::studentRoster[i]->getEmail().find(' ') != std::string::npos ||
			Roster::studentRoster[i]->getEmail().find('@') == std::string::npos || 
			Roster::studentRoster[i]->getEmail().find('.') == std::string::npos
			)
		{
			studentRoster[i]->print("email");
			cout << endl;
		}
	}
	cout << endl;
}

//prints Students from studentRoster grouped by DegreeProgram
void Roster::printByDegreeProgram(DegreeProgram degree) {
	//header of table, checks for degree program
	if (degree == DegreeProgram::Security) {
		cout << "Students in SECURITY:" << endl;
	}
	else if (degree == DegreeProgram::Network) {
		cout << "Students in NETWORK:" << endl;
	}
	else if (degree == DegreeProgram::Software) {
		cout << "Students in SOFTWARE:" << endl;
	}
	cout << "Format: Student ID | First Name | Last Name | Email | Age | Days In Course | Degree" << endl << endl;
	
	//prints info about Students from studentRoster based on degree
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRoster[i]->getDegreeProgram() == degree) {
				studentRoster[i]->print("all");
				cout << endl;
		}
	}
	cout << endl;
}

//destructor, deletes all Students in studentRoster and sets to nullpointer
Roster::~Roster() {
	cout << "Roster destructor called." << endl << endl;
	for (int i = 0; i < numStudents; i++) {
		delete studentRoster[i];
		studentRoster[i] = nullptr;
	}
	cout << endl << "Roster destruction complete." << endl;
}