#ifndef PAPER
#define PAPER

#include "Move.h"


class Paper : public Move {
private:
    int UID = 1;
    std::string name = "Paper";
public:
    int getUID();

    std::string getName();

    int isWinner(int Opponent);

};

#endif // PAPER