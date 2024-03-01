#ifndef HUMAN
#define HUMAN

#include <string>
using namespace std;

#include "Player.h"

class Human : public Player{
private:
    // store the players name
    string name;
public:
    // inisialise the player object with a name
    Human();
    Human(string name);

    // get the move of the player (based on input)
    char makeMove();

    // return the name of the player
    string getName();
};

#endif // HUMAN