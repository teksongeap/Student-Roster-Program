//header file for student.cpp, does not contain definitions
#pragma once
using std::string;

//static array degreeString used in print() function to avoid having to directly convert enums to strings
static const string degreeString[] = { "Security", "Network", "Software", "None" };

class Student {
private:
	int age;
	string lastName, firstName, email, studentID;
	const static int daysArraySize = 3;
	int numberOfDays[daysArraySize];
	DegreeProgram degree;

public:
	//getter functions
	int getAge();
	string getLastName();
	string getFirstName();
	string getEmail();
	string getStudentID();
	int *getNumberOfDays();
	DegreeProgram getDegreeProgram();

	//setter functions
	void setAge(int newAge);
	void setLastName(string newLastName);
	void setFirstName(string newFirstName);
	void setEmail(string newEmail);
	void setStudentID(string newStudentID);
	void setNumberOfDays(int *newNumberOfDays);
	void setDegreeProgram(DegreeProgram newDegreeProgram);

	//print function
	void print(string printInfo);

	//default constructor, constructor and destructor
	Student();
	Student(string studentID, string FirstName, string lastName, string email, int age, int *numberOfDays, DegreeProgram degree);
	~Student();
};