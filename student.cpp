#include "student.h"
#include "degree.h"
#include <iostream>


Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourses[0] = daysInCourse1;
    this->daysToCompleteCourses[1] = daysInCourse2;
    this->daysToCompleteCourses[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}


std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

int* Student::getDaysToCompleteCourses() {
    return daysToCompleteCourses;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}


void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysToCompleteCourses[0] = daysInCourse1;
    this->daysToCompleteCourses[1] = daysInCourse2;
    this->daysToCompleteCourses[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}


void Student::print() const {
    std::cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName()
        << "\tAge: " << getAge() << "\tdaysInCourse: {" << daysToCompleteCourses[0] << ", " << daysToCompleteCourses[1]
        << ", " << daysToCompleteCourses[2] << "} Degree Program: " << degreeProgramStrings[static_cast<int>(getDegreeProgram())] << "\n";
}
