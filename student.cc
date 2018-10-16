/*Student Class for WGU */

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"


Student::Student() {
    return;
};

Student:: ~Student() {
    return;
};

void Student:: print(){
    std::cout << "studentID: " << studentID << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Email Address: " << emailAddress << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Days in Course: " << daysInCourse[0] << ", " << 
            daysInCourse[1] << ", " << daysInCourse[2] << std::endl;
    return;
};

//Accessor Functions
string Student::studentIDGetter() {
    return studentID;
};

string Student::firstNameGetter() {
    return firstName;
};

string Student::lastNameGetter() {
    return lastName;
};

string Student::emailGetter() {
    return emailAddress;
};

int Student::ageGetter() {
    return age;
};

int Student::arrayGetter(int i){
    return daysInCourse[i];
};

enum Degree Student::getDegreeProgram() {
};
    

//Mutator Functions

void Student::studentIDSetter(string id) {
    studentID = id;
    return;
};

void Student::firstNameSetter(string fn) {
    firstName = fn;
    return;
};

void Student::lastNameSetter(string ln){
    lastName = ln;
    return;
};

void Student::emailSetter(string email) {
    emailAddress = email;
    return;
};

void Student::ageSetter(int howOld){
    age = howOld;
    return;
};

void Student::arraySetter(int num1, int num2, int num3) {
    daysInCourse[0] = num1;
    daysInCourse[1] = num2;
    daysInCourse[2] = num3;
};

