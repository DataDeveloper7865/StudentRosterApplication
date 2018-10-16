/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   networkStudent.h
 * Author: Stephen
 *
 * Created on August 11, 2018, 11:33 PM
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "degree.h"
#include "student.h"

class networkStudent : public Student {
public:
    networkStudent(string ID, string fn, string ln, string email,
        int howOld, int daysInCourse1, int daysInCourse2, int daysInCourse3,
        enum Degree = NETWORK);
    enum Degree getDegreeProgram();
    void print();
private:
    enum Degree deg = NETWORK;
};

#endif /* NETWORKSTUDENT_H */




