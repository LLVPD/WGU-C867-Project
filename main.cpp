#include <iostream>
#include <string>
#include "roster.h"

int main() {
    // === G1. Course header ===
    const std::string COURSE  = "Scripting and Programming - Applications – C867";
    const std::string LANGUAGE = "C++";
    const std::string WGU_ID  = "012474695";     // Filled per user
    const std::string NAME    = "Lamar Gibson";  // Filled per user

    std::cout << COURSE << std::endl;
    std::cout << "Language: " << LANGUAGE << std::endl;
    std::cout << "Student ID: " << WGU_ID << std::endl;
    std::cout << "Name: " << NAME << std::endl << std::endl;

    // === G2. Create an instance of Roster named classRoster ===
    Roster* classRoster = new Roster();

    // === Provided data (B updated for A5 with user's info) ===
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "012474695,Lamar,Gibson,lgibso22@wgu.edu,35,25,30,35,SOFTWARE"
    };

    // === G3. Add each student to classRoster ===
    for (const auto& row : studentData) {
        classRoster->parseAndAdd(row);
    }

    // === G4. Complete the rest of main per pseudo-code ===
    classRoster->printAll();
    std::cout << std::endl;

    classRoster->printInvalidEmails();
    std::cout << std::endl;

    // loop through classRosterArray and print average days for each student
    const char* ids[] = {"A1","A2","A3","A4","012474695"};
    for (const char* id : ids) {
        classRoster->printAverageDaysInCourse(id);
    }
    std::cout << std::endl;

    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    std::cout << std::endl;

    classRoster->remove("A3");
    std::cout << std::endl;

    classRoster->printAll();
    std::cout << std::endl;

    classRoster->remove("A3"); // expected: should print a message saying student not found
    std::cout << std::endl;

    delete classRoster;
    classRoster = nullptr;

    return 0;
}