//header file for roster.cpp, does not contain definitions
#pragma once
#include "student.h"
using std::string;

class Roster {
private:
	const static int numStudents = 5;
	Student *studentRoster[numStudents];
	int lastIndex = -1;
public:
	//parses string by comma into viable arguments for add() function
	void parse(string studentInfo);

	//adds Student object to studentRoster based on arguments passed after being parsed
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3,
		DegreeProgram degree);
	
	//removes Student from studentRoster based on studentID
	void remove(string studentID);

	//prints all information from studentRoster tabulated to look nice
	void printAll();
	
	//prints average days in course for Student object based on studentID
	void printAverageDaysInCourse(string studentID);
	
	//prints invalid emails from studentRoster
	//Criteria: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void printInvalidEmails();
	
	//prints Students from studentRoster grouped by DegreeProgram
	void printByDegreeProgram(DegreeProgram degree);

	//destructor
	~Roster();
};