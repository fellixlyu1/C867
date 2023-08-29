#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include <array>
using namespace std;

Roster::Roster(int numOfClasses) {
    this->numOfClasses = numOfClasses;
    this->index = 0;
    for (int i = 0; i < numOfClasses; i++) {
        this->rosterArr[i] = new Student;
    }
    return;
}

string Roster::GetStudentID(int index) {
    string studentID = rosterArr[index]->getStudentID();
    return studentID;
}

void Roster::parse(string studentData) {
    if (index < numOfClasses) {
        rosterArr[index] = new Student();
        int x = studentData.find(",");
        string studentID = studentData.substr(0, x);
        rosterArr[index]->SetID(studentID);

        int y = x + 1;
        x = studentData.find(",", y);
        string firstName = studentData.substr(y, x - y);
        rosterArr[index]->SetFirstName(firstName);

        y = x + 1;
        x = studentData.find(",", y);
        string lastName = studentData.substr(y, x - y);
        rosterArr[index]->SetLastName(lastName);

        y = x + 1;
        x = studentData.find(",", y);
        string emailAddress = studentData.substr(y, x - y);
        rosterArr[index]->SetEmailAddress(emailAddress);

        y = x + 1;
        x = studentData.find(",", y);
        int age = stoi(studentData.substr(y, x - y));
        rosterArr[index]->SetAge(age);

        y = x + 1;
        x = studentData.find(",", y);
        int daysInCourse1 = stoi(studentData.substr(y, x - y));

        y = x + 1;
        x = studentData.find(",", y);
        int daysInCourse2 = stoi(studentData.substr(y, x - y));

        y = x + 1;
        x = studentData.find(",", y);
        int daysInCourse3 = stoi(studentData.substr(y, x - y));
        rosterArr[index]->SetDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

        y = x + 1;
        x = studentData.find(",", y);
        DegreeProgram degreeProgram;
        string degreeString = studentData.substr(y, x - y);
        if (degreeString == "SECURITY") {
            rosterArr[index]->SetDegreeProgram(SECURITY);
        } else if (degreeString == "NETWORK") {
            rosterArr[index]->SetDegreeProgram(NETWORK);
        } else if (degreeString == "SOFTWARE") {
            rosterArr[index]->SetDegreeProgram(SOFTWARE);
        }

        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3,
            degreeProgram);

    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
                 int daysInCourse[Student::dArraySize]{daysInCourse1, daysInCourse2, daysInCourse3};
                 rosterArr[++index] = new Student(studentID, firstName, lastName, emailAddress,
                                              age, daysInCourse, degreeProgram);
};

void Roster::remove(string id) {

    bool foundStudent = false;
    for (int i = 0; i < numOfClasses; i++) {
        if (rosterArr[i] == nullptr) {
            continue;
        }
        else if (id == rosterArr[i]->getStudentID()) {
            rosterArr[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (foundStudent == false) {
        cout << "Error: Student " << id << " Not Found." << endl;
    }
    else if (foundStudent == true) {
        cout << "Student " << id << " removed." << endl;
    }
}

void Roster::printAll() {
    cout << "All current students: " << endl;
    for (int i = 0; i < numOfClasses; i++) {
        if (rosterArr[i] == nullptr)
        {
            continue;
        }
        else {
            rosterArr[i]->print();
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < numOfClasses; i++) {
        if (id == rosterArr[i]->getStudentID()) {
            cout << id << "" << "'s average days in the course:" <<
                 ((rosterArr[i]->GetDaysInCourse()[0] +
                   rosterArr[i]->GetDaysInCourse()[1] +
                   rosterArr[i]->GetDaysInCourse()[2]) / 3)
                 << endl;

        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < numOfClasses; ++i) {
        string emailAd = rosterArr[i]->GetEmailAddress();
        if ((emailAd.find('@') == string::npos) ||  (emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos)) {
            cout<<"Invalid Email Address:" << rosterArr[i]->getStudentID() << " Email Address " << emailAd << " is invalid." << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    string degreeString;
    if (degreeProgram == SECURITY) {
        degreeString = "SECURITY";
    }
    else if (degreeProgram == NETWORK) {
        degreeString = "NETWORK";
    }
    else if (degreeProgram == SOFTWARE) {
        degreeString = "SOFTWARE";
    }
    else {
        degreeString = "ERROR";
    }
    cout << "Students with degree program: " << degreeString << endl;
    int numStudents = 0;
    for (int i = 0; i < numOfClasses; i++) {
        if (rosterArr[i]->GetDegreeProgram() == degreeProgram) {
            rosterArr[i]->print();
            ++numStudents;
        }
    }
    if (numStudents == 0) {
        cout << "ERROR" << endl;
    }
}

Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete rosterArr[i];
        rosterArr[i] = nullptr;
    };
}