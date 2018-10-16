/*

 */

//
// File:   welcome.h
//

#ifndef _welcome_H
#define	_welcome_H
#include <string>
#include "degree.h"


using std::cout;
using std::endl;
using std::string;


class Student {
public:
    Student();
    ~Student();
    virtual void print();
    //accessor functions
    string studentIDGetter();
    string firstNameGetter();
    string lastNameGetter();
    string emailGetter();
    int ageGetter();
    int arrayGetter(int i);
    virtual enum Degree getDegreeProgram();
    
    //mutator functions
    void studentIDSetter(string studentID);
    void firstNameSetter(string firstName);
    void lastNameSetter(string lastName);
    void emailSetter(string emailAddress);
    void ageSetter(int age);
    void arraySetter(int num1, int num2, int num3);
    
protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    enum Degree deg;
};

    
#endif	/* _welcome_H */

