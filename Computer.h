#ifndef COMPUTER
#define COMPUTER

#include <string>

#include "Player.h"

class Computer : public Player{
public:
    // implement the virtual functions from player
    char makeMove();
    std::string getName();
};

#endif // COMPUTER