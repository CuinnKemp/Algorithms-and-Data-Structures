#include <string>

#include "Computer.h"

// computer will always return 'R' (rock) when makeMove() is called
Move* Computer::makeMove(){
    return this->move_factory.string_to_move("Rock");
}

// computer will always return "Computer" when getName() is called
std::string Computer::getName(){
    return "Computer";
}