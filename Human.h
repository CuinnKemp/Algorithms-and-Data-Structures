#ifndef HUMAN
#define HUMAN

#include <string>

#include "Player.h"

class Human : public Player{
private:
    // store the players name
    std::string name;
public:
    // inisialise the player object with a name
    Human();
    Human(std::string name);

    // get the move of the player (based on input)
    std::string makeMove();

    // return the name of the player
    std::string getName();
};

#endif // HUMAN