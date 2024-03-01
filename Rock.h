#ifndef ROCK
#define ROCK

#include "Move.h"

class Rock : public Move {
private:
    int UID = 2;
public:
    int getUID(){
        return UID;
    }

    int isWinner(int Opponent){
        if (Opponent > this->UID){
            return INVALID; // invalid Opponent UID
        } else if (Opponent == this->UID){
            return TIE; // tie
        } else {
            return LOSER;
        }
    }

};



#endif // ROCK