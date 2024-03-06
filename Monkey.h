#ifndef MONKEY
#define MONKEY

#include <string>

#include "Move.h"

class Monkey : public Move {
private:
    int UID = 4;
    std::string name = "Monkey";

public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);
};

#endif // MONKEY