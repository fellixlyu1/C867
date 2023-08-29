#include <iostream>
#include "roster.h"
#include "degree.h"
#include <string>
using namespace std;

int main() //Main
{ //This is the header for the project
    cout <<"Course Title: C867 - Scripting and Programming - Applications" << endl;
    cout <<"Programming Language: C++" << endl;
    cout <<"Student ID: 011326964" << endl;
    cout <<"Student Name: Dong Seong Lyu" << endl;
    cout << "	" << endl;
    cout << "	" << endl;
    //Below is the student data holding the necessary information
    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Dong Seong,Lyu,dlyu1@wgu.edu,28,55,183,193,SOFTWARE"
    };

    Roster * classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };

    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    classRoster->~Roster();
    delete classRoster;

}
