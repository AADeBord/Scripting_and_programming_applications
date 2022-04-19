#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//constructor
Student::Student() {
	string studentId = "none";
	string firstName = "none";
	string lastName = "none";
	string eMail = "none";
	int age = 0;
	int daysInCourse[] = { 0, 0, 0 };
	DegreeProgram degreeProgram = NETWORK;
	}

	
Student::Student(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse[3], DegreeProgram degreeProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->eMail = eMail;
	this->age = age;
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; ++i) {					// populate the array holding the 3 days to complete values
		this->daysInCourse[i] = daysInCourse[i];
	} 

	this->degreeProgram = degreeProgram;

}

// Data Getter / Accessor function definitions

string Student::GetStudentId() {
	return studentId;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmail() {
	return eMail;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
} 

// Data Setter / Mutator function definitions

void Student::SetStudentID(string studentId) {
	this->studentId = studentId;
	return;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::SetEmail(string eMail) {
	this->eMail = eMail;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	return;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;	
}

void Student::print() {
	cout << "Student ID: " << studentId << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "E-mail: " << eMail << "\t";
	cout << "Age: " << age << "\t";
	cout << "Days in Course: (";
	cout << daysInCourse[0] << " ," << daysInCourse[1] << " ," << daysInCourse[2] << ")" <<"\t";
	cout << "Degree Program: ";
	if (degreeProgram == SECURITY) {
		cout << "SECURITY" << endl;
		return;
	}
	if (degreeProgram == NETWORK) {
		cout << "NETWORK" << endl;
		return;
	}
	if (degreeProgram == SOFTWARE) {
		cout << "SOFTWARE" << endl;	
		return;
	}
}
