#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

class Roster {
private:
    static const int MAX_STUDENTS = 5;
    Student* classRosterArray[MAX_STUDENTS];
    int lastIndex;

public:
    Roster(); // Constructor
    ~Roster(); // Destructor

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(std::string studentID);

    void printAll() const;
    void printInvalidEmails() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    Student* getStudent(int index) const;
    int getLastIndex() const;
};

#endif
