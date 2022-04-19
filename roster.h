#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster {
public:

	Roster(int totalStudents);
	~Roster();

	void Parse(const string studentData[], int totalStudents);
	void Add(int arrayPosition, string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse[], DegreeProgram degreeProgram);
	void Remove(string studentId);
	void PrintAll();
	void PrintAverageDaysInCourse(string studentId);
	void PrintInvalidEmail();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);

	Student* classRosterArray[5];
	string studentData[5];
	int totalStudents;
	int arrayPosition;

private:
	int studentNum = 0;
	
	string studentId;
	string firstName;
	string lastName;
	string eMail;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	string degreeProgramString;


};


