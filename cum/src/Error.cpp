#include "Error.hpp"

Error::Error(std::string errorName, std::string details){
    this->errorName = errorName;
    this->details = details;
}

Error::Error(std::string details){
    this->details = details;
}

std::string Error::as_string(Position *posStart){
    std::string  res = errorName + " : "+ details;
    res += "\nFile '" + posStart->getFN()+"', line "+std::to_string(posStart->getLN()+1);
    return res; 
}


std::string Error::illegalCharErr(Position *posStart){
    this->errorName = "Illegal Character";
    return as_string(posStart);
}