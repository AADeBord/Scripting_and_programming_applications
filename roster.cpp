#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;




Roster::Roster(int totalStudents) {
	this->totalStudents = totalStudents;
	//this->classRosterArray[totalStudents] = new * Student [totalStudents]; // [totalStudents] ;
}
void Roster::Parse(const string studentData[], int totalStudents) {
	
	string studentId = "";
	string firstName = "";
	string lastName = "";
	string eMail = "";
	int age = 0;
	int daysInCourse[3];
	string degreeProgramString = "";
	DegreeProgram degreeProgram = SOFTWARE;
	this->totalStudents = totalStudents;
	int arrayPosition = 0;

		for (int i = 0; i < totalStudents; ++i) {
			int l = 0;
			int r = studentData[i].find(",");
			studentId = studentData[i].substr(l, r);

			l = r + 1;
			r = studentData[i].find(",", l);
			firstName = studentData[i].substr(l, r - l);

			l = r + 1;
			r = studentData[i].find(",", l);
			lastName = studentData[i].substr(l, r - l);

			l = r + 1;
			r = studentData[i].find(",", l);
			eMail = studentData[i].substr(l, r - l);

			l = r + 1;
			r = studentData[i].find(",", l);
			age = std::stoi(studentData[i].substr(l, r - l));

			l = r + 1;
			r = studentData[i].find(",", l);
			daysInCourse[0] = std::stoi(studentData[i].substr(l, r - l));

			l = r + 1;
			r = studentData[i].find(",", l);
			daysInCourse[1] = std::stoi(studentData[i].substr(l, r - l));

			l = r + 1;
			r = studentData[i].find(",", l);
			daysInCourse[2] = std::stoi(studentData[i].substr(l, r - l));
			
			l = r + 1;
			r = studentData[i].size();
			degreeProgramString = (studentData[i].substr(l, r - l));
			
			if (degreeProgramString == "NETWORK") {
				degreeProgram = NETWORK;
			}
			if (degreeProgramString == "SECURITY") {
				degreeProgram = SECURITY;
			}
			if (degreeProgramString == "SOFTWARE") {
				degreeProgram = SOFTWARE;
			}

			

			Add(arrayPosition, studentId, firstName, lastName, eMail, age, daysInCourse, degreeProgram);
			arrayPosition = arrayPosition + 1;

		}
		return;

}
void Roster::Add(int arrayPosition, string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	
	classRosterArray[arrayPosition] = new Student(studentId, firstName, lastName, eMail, age, daysInCourse, degreeProgram);
}
void Roster::PrintAll() {
	for (int i = 0; i < totalStudents; ++i) {
		classRosterArray[i]->print();
	
	} 
 }
void Roster::Remove(string studentId) {
	bool inRoster = false;
	int rosterPosition = 0;
	for (int i = 0; i < totalStudents; ++i) {
		if (classRosterArray[i]->GetStudentId() == studentId) {
			inRoster = true;
			rosterPosition = i;
			
		}
	}
			// If student is found remove them from roster,
			// then shift remaining students down one spot to keep students in order.
		if (inRoster == true) {
			cout << "Student " << studentId << " found and removed." << endl;
			delete classRosterArray[rosterPosition];
			while (rosterPosition < totalStudents - 1) {

				classRosterArray[rosterPosition] = classRosterArray[rosterPosition + 1];
				++rosterPosition;
			}
				totalStudents = totalStudents - 1;

		}
		if (inRoster == false) {
			cout << "Student " << studentId << " not found unable to remove." << endl;
		}
	}
void Roster::PrintAverageDaysInCourse(string studentId) {
	float average = 0;
		
	for (int i = 0; i < totalStudents; ++i) {
		
		if (classRosterArray[i]->GetStudentId() == studentId) {
			int* days = classRosterArray[i]->GetDaysInCourse();
			average = (days[0] + days[1] + days[2]) / 3.0;
			cout << "Student: " << classRosterArray[i]->GetStudentId() << " average days to complete 3 courses is " << average << endl;
		}

	}
}
void Roster::PrintInvalidEmail() {
	for (int i = 0; i < totalStudents; ++i) {
		
		if (classRosterArray[i]->GetEmail().find(' ') != std::string::npos || 
			classRosterArray[i]->GetEmail().find('@') == std::string::npos || 
			classRosterArray[i]->GetEmail().find('.', classRosterArray[i]->GetEmail().find('@')) == std::string::npos) {
			
				cout << classRosterArray[i]->GetStudentId() << ": \t" << classRosterArray[i]->GetEmail() << "\t Invalid E-mail, does not meet criteria." << endl;
				
		
		}
	}
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < totalStudents; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}
Roster::~Roster() {
	delete[] classRosterArray;
}
