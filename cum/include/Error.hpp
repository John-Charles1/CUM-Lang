#pragma once
#include <string>
#include "Position.hpp"
class Error{
public:
    Error(std::string errorName, std::string details);
    Error(std::string details);
    std::string as_string(Position *posStart);
    std::string illegalCharErr(Position *posStart);

private:
    std::string errorName;
    std::string details;
};

