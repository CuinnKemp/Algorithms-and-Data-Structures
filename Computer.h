#ifndef COMPUTER
#define COMPUTER

#include <string>
// using namespace std;

#include "Player.h"

class Computer : public Player{
public:
    // implement the virtual functions from player
    char makeMove();
    string getName();
};

#endif // COMPUTER