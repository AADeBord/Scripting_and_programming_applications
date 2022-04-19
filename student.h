#include <string>
#include "degree.h"
using namespace std;

class Student {
	
public:
	Student();
	Student(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse[3], DegreeProgram degreeProgram);

	// Data Getter / Accessor functions
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int *GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	// Data Setter / Mutator functions
	void SetStudentID(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string eMail);
	void SetAge(int age);
	void SetDaysInCourse(int daysInCourse[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	// print function
	void print();

// internal class viarables
private:
	string studentId;
	string firstName;
	string lastName;
	string eMail;
	int age;
	int *daysInCourse;
	DegreeProgram degreeProgram;


};
