#ifndef PIRATE
#define PIRATE

#include <unordered_set>
#include <string>

#include "Move.h"

class Pirate : public Move {
private:
    int UID = 6;
    std::string name = "Pirate";
public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);

};

#endif // PIRATE