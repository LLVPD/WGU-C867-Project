#include "student.h"
#include <iomanip>

Student::Student()
    : studentID(""), firstName(""), lastName(""),
      emailAddress(""), age(0), degreeProgram(DegreeProgram::SOFTWARE) {
    for (int i = 0; i < DAYS_ARRAY_SIZE; ++i) daysInCourse[i] = 0;
}

Student::Student(const std::string& studentID,
                 const std::string& firstName,
                 const std::string& lastName,
                 const std::string& emailAddress,
                 int age,
                 const int days[],
                 DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName),
      emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    for (int i = 0; i < DAYS_ARRAY_SIZE; ++i) daysInCourse[i] = days[i];
}

std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

void Student::setStudentID(const std::string& id) { studentID = id; }
void Student::setFirstName(const std::string& first) { firstName = first; }
void Student::setLastName(const std::string& last) { lastName = last; }
void Student::setEmailAddress(const std::string& email) { emailAddress = email; }
void Student::setAge(int a) { age = a; }
void Student::setDaysInCourse(const int days[]) {
    for (int i = 0; i < DAYS_ARRAY_SIZE; ++i) daysInCourse[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram program) { degreeProgram = program; }

void Student::print() const {
    std::cout << getStudentID() << '\t'
              << "First Name: " << getFirstName() << '\t'
              << "Last Name: "  << getLastName()  << '\t'
              << "Email: "      << getEmailAddress() << '\t'
              << "Age: "        << getAge() << '\t'
              << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} "
              << "Degree Program: " << degreeProgramToString(getDegreeProgram())
              << std::endl;
}