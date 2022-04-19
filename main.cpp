// wgu c867.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Aaron,DeBord,adebor3@wgu.edu,40,14,25,7,SOFTWARE"
    };

    // F.1 - Print out course title, Programing language, WGU ID, and Name
    cout << endl << "Class: C867 Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 002825642" << endl;
    cout << "Student Name: Aaron DeBord" << endl << endl;

    //F.2 Create instance of the class roster called classRoster
    Roster* classRoster = new Roster(5);
    //F.3 Parse and add each student to classRoster
    classRoster->Parse(studentData, 5);    
    //F.4a Use PrintAll() function to print the classRoster
    cout << "Complete class roster:" << endl << endl;
    classRoster->PrintAll();
    cout << endl;
    //F.4b Display invalid E-mails
    cout << "Invalid E-mails:" << endl << endl;
    classRoster->PrintInvalidEmail();
    cout << endl;
    //F.4c Loop through entire roster to display average days in a course for all students
    cout << "Average number of days to complete a course:" << endl;
    for (int i = 0; i < classRoster->totalStudents; ++i) {
        classRoster->PrintAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentId());
    }
    cout << endl;
    //F.4d Display student information of a specified degree type "SOFTWARE"
    cout << "Students sorted and dispayed by degree program parameter - Software: " << endl << endl;
    classRoster->PrintByDegreeProgram(SOFTWARE);
    cout << endl;
    //F.4e Remove student "A3" from the roster using student ID
    cout << "Remove a student from roster by student ID - A3:" << endl << endl;
    classRoster->Remove("A3");
    cout << endl;
    //F.4f Demonstrate the above student was removed by displaying the entire roster once again
    cout << "Display full roster to demonstrate A3 has been removed:" << endl << endl;
    classRoster->PrintAll();
    cout << endl;
    //F.4g Attempt to remove the same student once again. This should return an error because the student has been effectively removed
    cout << "Attempt to remove same student as above and demonstrate error returned:" << endl << endl;
    classRoster->Remove("A3");
    cout << endl;
    //F.5 Implement the destructor to relase the memory allocated
    

    return 0; 
    
    
    }

