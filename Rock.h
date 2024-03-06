#ifndef ROCK
#define ROCK

#include "Move.h"

class Rock : public Move {
private:
    int UID = 2;
    std::string name = "Rock";
public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);

};



#endif // ROCK