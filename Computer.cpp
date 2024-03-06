#include <string>

#include "Computer.h"

// computer will always return 'R' (rock) when makeMove() is called
std::string Computer::makeMove(){
    return "Rock";
}

// computer will always return "Computer" when getName() is called
std::string Computer::getName(){
    return "Computer";
}