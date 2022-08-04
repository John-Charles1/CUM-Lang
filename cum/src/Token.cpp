#include "Token.hpp"

Token::Token(std::string type, std::string value) :type(type), value(value)   {}

Token::Token(std::string type) :type(type)   {}

std::string Token::repr(){
    if(value.empty()){
        return this->type;
    }else{
        return this->type+" : "+this->value;
    }
}