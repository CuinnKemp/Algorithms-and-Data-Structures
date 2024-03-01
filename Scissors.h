#ifndef SCISSORS
#define SCISSORS

#include "Move.h"

class Scissors : public Move {
private:
    int UID = 3;
public:
    int getUID(){
        return UID;
    }

    int isWinner(int Opponent){
        if (Opponent > this->UID){
            return INVALID; // invalid Opponent UID
        } else if (Opponent == this->UID){
            return TIE; // tie
        }

        if (Opponent == this->UID-1){
            return LOSER;
        } else {
            return WINNER;
        }
    }

};



#endif // SCISSORS