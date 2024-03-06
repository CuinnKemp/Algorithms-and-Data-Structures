#ifndef SCISSORS
#define SCISSORS

#include<unordered_set>

#include "Move.h"

class Scissors : public Move {
private:
    int UID = 3;
    std::string name = "Scissors";
public:
    int getUID();
    
    std::string getName();

    int isWinner(int Opponent);

};



#endif // SCISSORS