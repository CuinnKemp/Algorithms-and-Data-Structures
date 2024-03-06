#include "Rock.h"

int Rock::getUID(){
    return UID;
}

std::string Rock::getName(){
    return name;
}

int Rock::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    } else {
        return LOSER;
    }
}