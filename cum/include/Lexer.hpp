#pragma once
#include "Token.hpp"
#include "Position.hpp"
#include <vector>
#include <string>
#include <iostream>

class Lexer{
public:
    Lexer(std::string fn, std::string text);
    void advance();
    Token makeNumber();
    std::vector<Token> makeTokens();

private:
    std::string fn;
    std::string text;
    Position *pos = NULL;
    std::string currentChar;
};