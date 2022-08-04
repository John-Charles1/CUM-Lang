#pragma once
#include <string>

#define TT_PLUS     "PLUS"
#define TT_MINUS    "MINUS"
#define TT_MUL      "MUL"
#define TT_DIV      "DIV"
#define TT_LPAREN   "RPAREN"
#define TT_RPAREN   "LPAREN"
#define TT_INT      "INTEGER"
#define TT_FLOAT    "FLOAT"

class Token{
public:
    Token(std::string type, std::string value);
    Token(std::string type);
    std::string repr();
private:
    std::string type;
    std::string value;
};
