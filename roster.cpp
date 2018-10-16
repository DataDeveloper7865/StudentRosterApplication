/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "degree.h"
#include "securityStudent.h"



//sets instance variable by calling respective student constructor
//and updates the roster
roster::roster() {
    return;
};

void roster::add(string id, string fn, string ln, string email,
    int age, int days1, int days2, int days3, enum Degree degreeProgram,
    int positionInArray) {
   
    
    if(degreeProgram == SECURITY) {
        Student* studentToAddPointer = nullptr;
        studentToAddPointer = new securityStudent(id, fn, ln, email, age, days1, days2, days3, degreeProgram);
        classRosterArray[positionInArray] = studentToAddPointer;
        cout << "security student successfully added to list" << endl;
        cout << endl;
        return;
        
    } else if (degreeProgram == NETWORK) {
        Student* studentToAddPointer = nullptr;
        studentToAddPointer = new networkStudent(id, fn, ln, email, age, days1, days2, days3, degreeProgram);
        classRosterArray[positionInArray] = studentToAddPointer;
        cout << "network student successfully added to list" << endl;
        cout << endl;
        return;
        
    } else {
        Student* studentToAddPointer = nullptr;
        studentToAddPointer = new softwareStudent(id, fn, ln, email, age, days1, days2, days3, degreeProgram);
        classRosterArray[positionInArray] = studentToAddPointer;
        cout << "software student successfully added to list" << endl;
        cout << endl;
        return;
        
    };
    return;
};

//removes students from roster by studentID. If student does not exist, the function
//print an error message indicating that the student was not found.******************
void roster::remove(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else if (classRosterArray[i]->studentIDGetter() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            cout << "Student removed from system" << endl;
            cout << endl;
            return;
        }; 
    };
    cout << "I'm sorry. That student was not found" << endl;
    cout << "Please try another student." << endl;
    cout << endl;
    return;
};

//prints a complete tab-separated list of student data using accessor functions
void roster::printAll(){
    cout << "printAll function successfully called" << endl;
    cout << endl;
    cout << "ID" << "\t" << "First Name" << "\t" << "Last Name" << "\t" << "Email" <<
            "\t" << "Age" << "\t" << "days1" << "\t" << "days2" << "\t" << "days3" <<
            "\t" << "Degree" << endl;
    for (int i = 0; i < 5; i++) {
        cout << classRosterArray[i]->studentIDGetter() << "\t";
        cout << classRosterArray[i]->firstNameGetter() << "\t";
        cout << classRosterArray[i]->lastNameGetter() << "\t";
        cout << classRosterArray[i]->emailGetter() << "\t";
        cout << classRosterArray[i]->ageGetter() << "\t";
        cout << classRosterArray[i]->arrayGetter(0) << "\t";
        cout << classRosterArray[i]->arrayGetter(1) << "\t";
        cout << classRosterArray[i]->arrayGetter(2) << "\t";  
        cout << classRosterArray[i]->getDegreeProgram() << "\t";
        cout << endl;
    }
    cout << endl;
    return;
};

//prints a student's average number of days in the three courses with student
//identified by the studentID parameter.************************************
void roster::printDaysInCourse(string studentID) {
    cout << "printDaysInCouse function successfully called" << endl;
    cout << endl;
    int average;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->studentIDGetter() == studentID) {
        average = ((classRosterArray[i]->arrayGetter(0) +
                classRosterArray[i]->arrayGetter(1) +
                classRosterArray[i]->arrayGetter(2)) / 3 );
        };
    };
    cout << "The students average number of days in courses is: " << average << endl;
    cout << endl;
    return;
};

void roster::printInvalidEmails() {
    cout << "printInvalidEmails function successfully called" << endl;
    
    for (int i=0; i < 5; ++i) {
        std::string s = classRosterArray[i]->emailGetter();
        
        
        if (s.find("@") == string::npos || s.find(".") == string::npos || s.find(" ") != string::npos) {
                cout << "Invalid Email: " << classRosterArray[i]->emailGetter() << endl;
            }
    }
   return;
};

//prints out student information for a degree program specified by an enumerated type
void roster::printByDegreeProgram(int degreeProgram) {
    cout << "printByDegreeProgram function successfully called" << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        };
    };
    return;
};

//destructor
roster::~roster(){
    cout << "destructor called" << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = NULL;
    }
    return;
};

int main() {
    
    cout << "Scripting and Programming Applications - C867" << endl;
    cout << "C++ was used to create this program" << endl;
    cout << "Created By: Stephen Whelan, Student ID: 000904690" << endl;
    cout << "Submitted to WGU on 26AUG2018" << endl; 
    cout << endl;
            
            
    roster classRoster;      //instance of Roster class, called classRoster, created.
    
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Stephen,Whelan,swhela7@wgu.edu,27,50,50,50,SOFTWARE"};
            
    for (int i = 0; i < 5; i++) {
        std::string s = studentData[i];
        std::string delimiter = ",";
        std::string studentDataHolder[9];
        int counter = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos && counter < 9){
            token = s.substr(0, pos);
            //add to studentDataList
            studentDataHolder[counter] = token;
            s.erase(0,pos + delimiter.length());
            if (counter == 7) {
                studentDataHolder[counter+1] = s.substr((pos-2), s.length());
            }
            counter++;
        }
        
        //apply pointer operations through the use of the add function
        if (studentDataHolder[8] == "SECURITY") {
            //add the security student to classRoster
            classRoster.add(studentDataHolder[0],studentDataHolder[1],studentDataHolder[2],
                    studentDataHolder[3],stoi(studentDataHolder[4]),stoi(studentDataHolder[5]),
                    stoi(studentDataHolder[6]),stoi(studentDataHolder[7]),SECURITY,i);
        }
        else if (studentDataHolder[8] == "NETWORK") {
            //add the network student to classRoster
            classRoster.add(studentDataHolder[0],studentDataHolder[1],studentDataHolder[2],
                    studentDataHolder[3],stoi(studentDataHolder[4]),stoi(studentDataHolder[5]),
                    stoi(studentDataHolder[6]),stoi(studentDataHolder[7]),NETWORK,i);
        }
        else {
            //add the software student to classRoster
            classRoster.add(studentDataHolder[0],studentDataHolder[1],studentDataHolder[2],
                    studentDataHolder[3],stoi(studentDataHolder[4]),stoi(studentDataHolder[5]),
                    stoi(studentDataHolder[6]),stoi(studentDataHolder[7]),SOFTWARE,i);
        }
    }
            
          
    classRoster.printAll();       //Call the printAll function
    classRoster.printInvalidEmails();  //Print the invalid emails
    
    
    //loop through classRosterArray and for each element print average days in course
    for (int i =0; i < 5; i++) {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->studentIDGetter());
    }
    
    
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    
    
    
    //~roster();   //Destructor implicitly called
    
    return 0;
};
    
    
    