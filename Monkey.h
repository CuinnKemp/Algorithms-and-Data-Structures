#ifndef MONKEY
#define MONKEY

#include "Move.h"

class Monkey : public Move {
private:
    int UID = 4;
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
        return TIE; // there is no UID less than this->UID hence always will be a tie
    }

};

#endif // MONKEY