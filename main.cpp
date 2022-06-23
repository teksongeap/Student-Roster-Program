//main file for project

#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() {
	//project information
	cout << "Course: C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 009489418" << endl;
	cout << "Name: Teksong Eap" << endl << endl;

	//input data for program
	const string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Teksong,Eap,teap@wgu.edu,25,25,26,27,SOFTWARE" 
	};

	Roster classRoster;

	//parses and adds each student to classRoster
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	//prints all info in student table
	classRoster.printAll();

	//prints all invalid emails
	classRoster.printInvalidEmails();
	
	//iterates through studentIDArray to print averages days in course according to ID
	const string studentIDArray[] = { "A1", "A2", "A3", "A4", "A5" };
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(studentIDArray[i]);
	}

	//print by specified degree program enumerated type
	classRoster.printByDegreeProgram(DegreeProgram::Software);

	//Removes student A3
	classRoster.remove("A3");
	classRoster.printAll();

	//should return "Student not found!""
	classRoster.remove("A3");

	return 0;
}