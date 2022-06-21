//header file for student.cpp, does not contain definitions
#pragma once
class Student {
private:
	int age;
	string lastName, firstName, email, studentID;

public:
	//getter functions
	int getAge() const;
	string getLastName() const;
	string getFirstName() const;
	string getEmail() const;
	string getStudentID() const;
	int numberOfDays[arrSize];

	//setter functions
	void setAge(int newAge);
	void setLastName(string newLastName);
	void setFirstName(string newFirstName);
	void setEmail(string newEmail);
	void setStudentID(string newStudentID);
	
	//constructors and destructor
	~Student();

};