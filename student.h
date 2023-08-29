//
// Created by Dong Seong Lyu on 7/20/23.
//
#ifndef student_h
#define student_h
#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
    //Empty Constructor
    Student();
    //Destructor
    ~Student();
    //Parameterized Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age,
            int daysInCourse[], DegreeProgram degreeProgram);
    const static int dArraySize = 3;
    //Getters
    string getStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram();
    //Setters
    void SetID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int studentAge);
    void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    void print();
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[dArraySize];
    int i = 0;
    DegreeProgram degreeProgram;
};
#endif