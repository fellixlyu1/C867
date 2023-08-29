//
// Created by Dong Seong Lyu on 7/20/23.
//
#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse[0] = 0;
    this->daysInCourse[1] = 0;
    this->daysInCourse[2] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
};

Student::~Student() {}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degreeProgram = degreeProgram;
}
//Accessor for the Getters
string Student::getStudentID() {return studentID;}
string Student::GetFirstName() {return firstName;}
string Student::GetLastName() {return lastName;}
string Student::GetEmailAddress() {return emailAddress;}
int Student::GetAge() {return age;}
int* Student::GetDaysInCourse() {return daysInCourse;}
DegreeProgram Student::GetDegreeProgram() {return degreeProgram;}
//Mutator for the Setters
void Student::SetID(string studentID) {this->studentID = studentID;}
void Student::SetFirstName(string firstName) {this->firstName = firstName;}
void Student::SetLastName(string lastName) {this->lastName = lastName;}
void Student::SetEmailAddress(string emailAddress) {this->emailAddress = emailAddress;}
void Student::SetAge(int studentAge) {this->age = studentAge;}
void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    for (int i = 0; i < 3; i++)
        this->daysInCourse[0] = daysInCourse1;
        this->daysInCourse[1] = daysInCourse2;
        this->daysInCourse[2] = daysInCourse3;
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}
//Prints out the Student Data
void Student::print() {
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

    cout << studentID
         << "   First Name: " << GetFirstName()
         << "   Last Name: " << GetLastName()
         << "   Age: " << GetAge() << "  "
         << "Days in courses: {" << GetDaysInCourse()[0] << " " << GetDaysInCourse()[1] << " "
         << GetDaysInCourse()[2] << "} Degree Program: " << degreeString << " "<< endl;
}
