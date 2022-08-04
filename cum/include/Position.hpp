#pragma once
#include <string>

class Position{
public:
    Position(int idx, int ln, int col, std::string fn, std::string ftxt);
    void advance(std::string currentChar);
    Position copy();
    int getIDX();
    int getLN();
    int getCOL();
    std::string getFN();
    std::string getFTXT();
    void setIDX(int idx);
    void setLN(int ln);
    void setCOL(int col);
    void setFN(std::string fn);
    void setFTXT(std::string ftxt);
private:
    int idx;
    int ln;
    int col;
    std::string fn;
    std::string ftxt;
};