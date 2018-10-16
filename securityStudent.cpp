/*
 * security student subclass
 */

#include <iostream>
#include <string>
#include "securityStudent.h"
#include "degree.h"
#include "student.h"



securityStudent::securityStudent(string ID, string fn, string ln, string email,
        int howOld, int daysInCourse1, int daysInCourse2, int daysInCourse3,
        enum Degree SECURITY) {
    studentID = ID;
    firstName = fn;
    lastName = ln;
    emailAddress = email;
    age = howOld;
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
     return;
    };
    
    
void securityStudent::print() {
    std::cout << "studentID: " << Student::studentIDGetter() << std::endl;
    std::cout << "First Name: " << Student::firstNameGetter() << std::endl;
    std::cout << "Last Name: " << Student::lastNameGetter() << std::endl;
    std::cout << "Email Address: " << Student::emailGetter() << std::endl;
    std::cout << "Age: " << Student::ageGetter() << std::endl;
    std::cout << "Days in Course1: " << Student::arrayGetter(0) << std::endl;
    std::cout << "Days in Course2: " << Student::arrayGetter(1) << std::endl;
    std::cout << "Days in Course3: " << Student::arrayGetter(2)<< std::endl;
    std::cout << "degree program: 0:SECURITY, 1:NETWORK, 2:SOFTWARE:   " << getDegreeProgram() << std::endl;
    std::cout << endl;
    return;
    }
    
enum Degree securityStudent::getDegreeProgram() {
    return deg; 
};