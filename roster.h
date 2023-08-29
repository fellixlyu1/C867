//
// Created by Dong Seong Lyu on 7/20/23.
//
#ifndef roster_h
#define roster_h
#pragma once
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
public:
    int numOfClasses; //Size of class required for array
    Student* rosterArr[5]; //Pointer array for the student roster
    Roster(int numOfClasses); //Constructor
    ~Roster(); //Destructor
    string GetStudentID(int index);
    void parse(string studentData);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void add(string studentID, string firstName, string lastName, string emailAddress,
             int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3,
             DegreeProgram degreeProgram);
private:
    int index = -1;
};

#endif