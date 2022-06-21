//header file for student.cpp, does not contain definitions
#pragma once
using std::string;

//static array degreeString used in print() function to avoid having to directly convert enums to strings
static const string degreeString[] = { "Security", "Network", "Software", "None" };

class student {
private:
	int age;
	string lastName, firstName, email, studentID;
	const static int daysArraySize = 4;
	int numberOfDays[daysArraySize];
	degreeProgram degree;

public:
	//getter functions
	int getAge();
	string getLastName();
	string getFirstName();
	string getEmail();
	string getStudentID();
	int* getNumberOfDays();
	degreeProgram getDegreeProgram();

	//setter functions
	void setAge(int newAge);
	void setLastName(string newLastName);
	void setFirstName(string newFirstName);
	void setEmail(string newEmail);
	void setStudentID(string newStudentID);
	void setNumberOfDays(int* newNumberOfDays);
	void setDegreeProgram(degreeProgram newDegreeProgram);

	//print function
	void print(string printInfo);

	//default constructor, constructor and destructor
	student();
	student(int age, string lastName, string FirstName, string email, string studentID, int numberOfDays[], degreeProgram degree);
	~student();
};