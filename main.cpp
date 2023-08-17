#include <iostream>
#include <string>
#include <sstream>
#include "degree.h"
#include "student.h"
#include "roster.h"

int main() {
    std::cout << "Course Title: C867 Scripting and Programming - Applications\n";
       std::cout << "Programming Language: C++\n";
       std::cout << "Student ID: 011122107\n";
       std::cout << "Name: Jacob Lopez\n";
    
    Roster classRoster;

    const std::string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jacob,Lopez,jlop@wgu.edu,20,30,30,30,SOFTWARE"
    };

    for (const std::string& data : studentData) {
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        std::string studentID = tokens[0];
        std::string firstName = tokens[1];
        std::string lastName = tokens[2];
        std::string emailAddress = tokens[3];
        int age = std::stoi(tokens[4]);
        int daysInCourse1 = std::stoi(tokens[5]);
        int daysInCourse2 = std::stoi(tokens[6]);
        int daysInCourse3 = std::stoi(tokens[7]);
        DegreeProgram degreeProgram;
        
        
        if (tokens[8] == "SECURITY") {
            degreeProgram = DegreeProgram::SECURITY;
        } else if (tokens[8] == "NETWORK") {
            degreeProgram = DegreeProgram::NETWORK;
        } else if (tokens[8] == "SOFTWARE") {
            degreeProgram = DegreeProgram::SOFTWARE;
        } else {
            degreeProgram = DegreeProgram::SOFTWARE;
        }

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

    // Print all student data
    classRoster.printAll();

    // Print invalid email addresses
    classRoster.printInvalidEmails();

    // print average days in course
    for (int i = 0; i <= classRoster.getLastIndex(); ++i) {
        classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
    }

    // Print students by degree program
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    // Remove student with ID "A3"
    classRoster.remove("A3");

    // Print all student data after removal
    classRoster.printAll();

    // Try to remove the student with ID "A3" again (error message)
    classRoster.remove("A3");

    return 0;
}
