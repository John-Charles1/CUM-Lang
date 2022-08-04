#include "Token.hpp"
#include "Lexer.hpp"
#include <iostream>
#include <string>
#include <vector>
#define Log(x) std::cout << x << std::endl

namespace Run{
    void run(){
        std::string text;
        while(true){
            std::cout << "cum >: ";
            std::getline(std::cin, text);
            Lexer lexer("stdin", text);
            std::vector<Token> tokens = lexer.makeTokens();
            text += '\n';
            for(int i = 0; i < tokens.size(); i++){
                std::cout << "["<<tokens[i].repr() <<"]";
            }

            std::cout << std::endl;
        }
    }
}