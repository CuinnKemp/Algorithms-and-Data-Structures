#ifndef MONKEY
#define MONKEY

#include <string>

#include "Move.h"

class Monkey : public Move {
private:
    // set Monkey UID
    int UID = 4;

    // set move name
    std::string name = "Monkey";

public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);
};

#endif // MONKEY