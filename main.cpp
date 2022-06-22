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
	cout << "Name: Teksong Eap" << endl;

	//input data for program
	const string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Teksong,Eap,teap@wgu.edu,25,25,26,27,SOFTWARE" 
	};

	//adds each student to classRoster

	classRoster.printAll();

	classRoster.printInvalidEmails();

	//below will be turned into a for loop
	classRoster.printAverageDaysInCourse(/*current_object's student id*/);

	classRoster.printByDegreeProgram(Software);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	return 0;
}