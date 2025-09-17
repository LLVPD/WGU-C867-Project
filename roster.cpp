#include "roster.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

int Roster::findIndexByID(const std::string& studentID) const {
    for (size_t i = 0; i < classRosterArray.size(); ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Roster::add(std::string studentID,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram) {
    int days[Student::DAYS_ARRAY_SIZE] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student* s = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
    classRosterArray.push_back(s);
}

void Roster::remove(std::string studentID) {
    int idx = findIndexByID(studentID);
    if (idx == -1) {
        std::cout << "ERROR: Student with ID " << studentID << " was not found." << std::endl;
        return;
    }
    delete classRosterArray[idx];
    classRosterArray[idx] = nullptr;
    classRosterArray.erase(classRosterArray.begin() + idx);
}

void Roster::printAll() const {
    for (const auto* s : classRosterArray) {
        if (s) s->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
    int idx = findIndexByID(studentID);
    if (idx == -1 || !classRosterArray[idx]) {
        std::cout << "Cannot compute average: student " << studentID << " not found." << std::endl;
        return;
    }
    const int* d = classRosterArray[idx]->getDaysInCourse();
    double avg = (d[0] + d[1] + d[2]) / 3.0;
    std::cout << "Average days in course for student " << studentID << ": " << avg << std::endl;
}

void Roster::printInvalidEmails() const {
    std::cout << "Invalid emails:" << std::endl;
    for (const auto* s : classRosterArray) {
        if (!s) continue;
        const std::string& e = s->getEmailAddress();
        bool hasAt = e.find('@') != std::string::npos;
        bool hasDot = e.find('.') != std::string::npos;
        bool hasSpace = e.find(' ') != std::string::npos;
        if (!hasAt || !hasDot || hasSpace) {
            std::cout << e << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const auto* s : classRosterArray) {
        if (s && s->getDegreeProgram() == degreeProgram) {
            s->print();
        }
    }
}

Roster::~Roster() {
    for (auto*& s : classRosterArray) {
        delete s;
        s = nullptr;
    }
    classRosterArray.clear();
}

void Roster::parseAndAdd(const std::string& csvRow) {
    std::stringstream ss(csvRow);
    std::string token;

    std::string id, first, last, email, ageStr, d1Str, d2Str, d3Str, degreeStr;

    std::getline(ss, id, ',');
    std::getline(ss, first, ',');
    std::getline(ss, last, ',');
    std::getline(ss, email, ',');
    std::getline(ss, ageStr, ',');
    std::getline(ss, d1Str, ',');
    std::getline(ss, d2Str, ',');
    std::getline(ss, d3Str, ',');
    std::getline(ss, degreeStr, ',');

    auto trim = [](std::string& s){
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front()))) s.erase(s.begin());
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back()))) s.pop_back();
    };
    trim(email);
    trim(degreeStr);

    int age = std::stoi(ageStr);
    int d1 = std::stoi(d1Str);
    int d2 = std::stoi(d2Str);
    int d3 = std::stoi(d3Str);

    DegreeProgram dp = DegreeProgram::SOFTWARE;
    if (degreeStr == "SECURITY") dp = DegreeProgram::SECURITY;
    else if (degreeStr == "NETWORK") dp = DegreeProgram::NETWORK;
    else if (degreeStr == "SOFTWARE") dp = DegreeProgram::SOFTWARE;

    add(id, first, last, email, age, d1, d2, d3, dp);
}