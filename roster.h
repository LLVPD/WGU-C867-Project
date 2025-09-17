#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string>
#include "student.h"

class Roster {
private:
    std::vector<Student*> classRosterArray;
    int findIndexByID(const std::string& studentID) const;

public:
    void add(std::string studentID,
             std::string firstName,
             std::string lastName,
             std::string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);

    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    ~Roster();
    void parseAndAdd(const std::string& csvRow);
};

#endif // ROSTER_H