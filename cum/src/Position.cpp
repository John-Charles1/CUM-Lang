#include "Position.hpp"

Position::Position(int idx, int ln, int col, std::string fn, std::string ftxt)    
:idx(idx), ln(ln), col(col), fn(fn), ftxt(ftxt){

}
void Position::advance(std::string currentChar){
    this->idx++;
    this->col++;
    if(currentChar == "\n"){
        this->ln++;
        this->col = 0;
    }
}
Position Position::copy(){
    return Position(this->idx, this->ln, this->col, this->fn, this->ftxt);
}

int Position::getIDX(){
    return this->idx;
}
int Position::getLN(){
    return this->ln;
}
int Position::getCOL(){
    return this->col;
}

std::string Position::getFN(){
    return this->fn;
}
std::string Position::getFTXT(){
    return this->ftxt;
}
void Position::setIDX(int idx){
    this->idx = idx;
}
void Position::setLN(int ln){
    this->ln = ln;
}
void Position::setCOL(int col){
    this->col = col;
}
void Position::setFN(std::string fn){
    this->fn = fn;
}
void Position::setFTXT(std::string ftxt){
    this->ftxt = ftxt;
}