#include "roster.h"
#include <iostream>

Roster::Roster() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        classRosterArray[i] = nullptr;
    }
    lastIndex = -1;
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    
    Student* student = new Student(studentID, firstName, lastName, emailAddress, age,
        daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

    
    classRosterArray[++lastIndex] = student;
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            if (i < lastIndex) {
                classRosterArray[i] = classRosterArray[lastIndex];
                classRosterArray[lastIndex] = nullptr;
            }
            lastIndex--;
            break;
        }
    }
    if (!found) {
        std::cout << "Error: Student with ID " << studentID << " not found.\n";
    }
}

void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
}

void Roster::printInvalidEmails() const {
    bool anyInvalid = false;
    for (int i = 0; i <= lastIndex; ++i) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            anyInvalid = true;
            std::cout << "Invalid email address: " << email << "\n";
        }
    }
    if (!anyInvalid) {
        std::cout << "All email addresses are valid.\n";
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
    int totalDays = 0;
    int numCourses = 3;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysToCompleteCourses();
            totalDays = days[0] + days[1] + days[2];
            break;
        }
    }
    std::cout << "Average number of days in courses for student " << studentID << ": " << totalDays / numCourses << "\n";
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Student* Roster::getStudent(int index) const {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    }
    return nullptr;
}

int Roster::getLastIndex() const {
    return lastIndex;
}
