#include "Lexer.hpp"
#include "Error.hpp"

Lexer::Lexer(std::string fn, std::string text)
:text(text), fn(fn)
{
    this->pos = new Position(-1,0,-1, this->fn, this->text);
    this->currentChar = "";
    this->advance();
}
void Lexer::advance(){
    this->pos->advance(this->currentChar);
    std::string s(1, this->text[this->pos->getIDX()]);
    this->currentChar = this->pos->getIDX() < this->text.size() ? s : "";
}
std::vector<Token> Lexer::makeTokens(){
    std::vector<Token> tokens;
    while(this->currentChar != ""){
        if(this->currentChar == "\t" || this->currentChar == " "){
            this->advance();
        }else if(this->currentChar == "0" || this->currentChar == "1" || this->currentChar == "2" ||
        this->currentChar == "3" || this->currentChar == "4" || this->currentChar == "5" ||
        this->currentChar == "6" || this->currentChar == "7" || this->currentChar == "8" || this->currentChar == "9"){
            tokens.push_back(this->makeNumber());
        }else if(this->currentChar == "+"){
            tokens.push_back(Token(TT_PLUS));
            this->advance();
        }else if(this->currentChar == "-"){
            tokens.push_back(Token(TT_MINUS));
            this->advance();
        }else if(this->currentChar == "*"){
            tokens.push_back(Token(TT_MUL));
            this->advance();
        }else if(this->currentChar == "/"){
            tokens.push_back(Token(TT_DIV));
            this->advance();
        }else if(this->currentChar == "("){
            tokens.push_back(Token(TT_LPAREN));
            this->advance();
        }else if(this->currentChar == ")"){
            tokens.push_back(Token(TT_RPAREN));
            this->advance();
        }else{
            Position *p = this->pos;
            std::cout << Error(this->currentChar).illegalCharErr(p);
            return {};
            break;
        }
    }
    return tokens;
}
Token Lexer::makeNumber(){
    int dotCount = 0;
    std::string numStr;
    while(this->currentChar != "" && this->currentChar == "0" || this->currentChar == "1" || this->currentChar == "2" ||
        this->currentChar == "3" || this->currentChar == "4" || this->currentChar == "5" ||
        this->currentChar == "6" || this->currentChar == "7" || this->currentChar == "8" || this->currentChar == "9" || this->currentChar == ".")
    {
        if(this->currentChar == "."){
            if(dotCount == 1) break;
            dotCount++;
            numStr += ".";
        }else{
            numStr += this->currentChar;
        }
        this->advance();
    }
    if(dotCount == 0)
        return(Token(TT_INT, numStr));
        else
            return(Token(TT_FLOAT, numStr));
}