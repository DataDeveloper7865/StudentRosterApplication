/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   securityStudent.h
 * Author: Stephen
 *
 * Created on August 11, 2018, 11:33 PM
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "degree.h"
#include "student.h"

class securityStudent : public Student {
public:
    securityStudent(string ID, string fn, string ln, string email,
        int howOld, int daysInCourse1, int daysInCourse2, int daysInCourse3,
        enum Degree = SECURITY);
    enum Degree getDegreeProgram();
    void print();
    enum Degree deg = SECURITY;
};

#endif /* SECURITYSTUDENT_H */

