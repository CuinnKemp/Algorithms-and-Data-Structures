#ifndef ZOMBIE
#define ZOMBIE

#include <unordered_set>
#include <string>

#include "Move.h"

class Zombie : public Move {
private:
    int UID = 8;
    std::string name = "Zombie";
public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);

};

#endif // ZOMBIE