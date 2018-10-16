/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   roster.h
 * Author: Stephen
 *
 * Created on August 12, 2018, 9:27 PM
 */

#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "degree.h"

class roster {
public:
    roster();
    ~roster();
    int positionInArray;
    void add(string id, string fn, string ln, string email,
    int age, int days1, int days2, int days3, enum Degree degreeProgram,
    int positionInArray);
    void remove(string studentID);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeProgram); 
    Student * classRosterArray[5];
};


#endif /* ROSTER_H */

