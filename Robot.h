#ifndef ROBOT
#define ROBOT

#include <unordered_set>
#include <string>

#include "Move.h"

class Robot : public Move {
private:
    int UID = 5;
    std::string name = "Robot";
public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);

};

#endif // ROBOT