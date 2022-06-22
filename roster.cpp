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
	string degreeFirst2Letters; //used to avoid trying to convert string to enum
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
		
		switch (nextArg)
		{
		case 2: //switch case for first name
			rightSide = studentInfo.find(",", leftSide);
			fName = studentInfo.substr(leftSide, rightSide - leftSide);
			break;
		case 3: //switch case for last name
			rightSide = studentInfo.find(",", leftSide);
			lName = studentInfo.substr(leftSide, rightSide - leftSide);
			break;
		case 4: //switch case for email
			rightSide = studentInfo.find(",", leftSide);
			email = studentInfo.substr(leftSide, rightSide - leftSide);
			break;
		case 5: //switch case for age, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			age = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
			break;
		case 6: //switch case for days1, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			days1 = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
			break;
		case 7: //switch case for days2, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			days2 = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
			break;
		case 8: //switch case for days3, converts string to int
			rightSide = studentInfo.find(",", leftSide);
			days3 = stoi(studentInfo.substr(leftSide, rightSide - leftSide));
			break;
		case 9: //switch case for degree program, grabs first 2 letters and uses it to determine degree
			 degreeFirst2Letters = studentInfo.substr(leftSide, leftSide + 2);
			 if (degreeFirst2Letters == "Se") {
				 degree = DegreeProgram::Security;
			 }
			 else if (degreeFirst2Letters == "Ne") {
				 degree = DegreeProgram::Network;
			 }
			 else if (degreeFirst2Letters == "So") {
				 degree = DegreeProgram::Software;
			 }
			 else {
				 cout << "Incorrect input on case 9 switch in parse() or no degree program." << endl;
			 }
			break;
		default:
			break;
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
	int daysArr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

}

//removes Student from studentRoster based on studentID
void Roster::remove(string studentID) {

}

//prints all information from studentRoster tabulated to look nice
void Roster::printAll() {

}

//prints average days in course for Student object based on studentID
void Roster::printAverageDaysInCourse(string studentID) {

}

//prints invalid emails from studentRoster
//Criteria: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {

}

//prints Students from studentRoster grouped by DegreeProgram
void Roster::printByDegreeProgram(DegreeProgram degree) {

}

//destructor, deletes all Students in studentRoster and sets to nullpointer
Roster::~Roster() {
	cout << "Roster destructor has been called." << endl << endl;
	for (int i = 0; i < numStudents; i++) {
		delete studentRoster[i];
		studentRoster[i] = nullptr;
	}
	cout << "Roster destruction complete." << endl;
}