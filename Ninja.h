#ifndef NINJA
#define NINJA

#include <unordered_set>
#include <string>

#include "Move.h"

class Ninja : public Move {
private:
    int UID = 7;
    std::string name = "Ninja";
public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);

};

#endif // NINJA