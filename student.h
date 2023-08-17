#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToCompleteCourses[3];
    DegreeProgram degreeProgram;

public:
    
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    int* getDaysToCompleteCourses();
    DegreeProgram getDegreeProgram() const;

    
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    
    void print() const;
};

#endif
