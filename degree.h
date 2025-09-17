#ifndef DEGREE_H
#define DEGREE_H

#include <string>

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };

inline std::string degreeProgramToString(DegreeProgram dp) {
    switch (dp) {
        case DegreeProgram::SECURITY: return "Security";
        case DegreeProgram::NETWORK:  return "Network";
        case DegreeProgram::SOFTWARE: return "Software";
        default: return "Unknown";
    }
}

#endif // DEGREE_H