#ifndef PAPER
#define PAPER

#include "Move.h"


class Paper : public Move {
private:
    int UID = 1;
    std::string name = "Paper";
public:
    int getUID(){
        return UID;
    }

    std::string getName(){
        return name;
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

#endif // PAPER