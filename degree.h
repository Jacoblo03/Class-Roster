#ifndef DEGREE_H
#define DEGREE_H

#include <string>


enum class DegreeProgram {
    SECURITY,
    NETWORK,
    SOFTWARE
};


inline const std::string degreeProgramStrings[] = {
    "SECURITY",
    "NETWORK",
    "SOFTWARE"
};

#endif
