#include "Paper.h"

int Paper::getUID(){
    return UID;
}

std::string Paper::getName(){
    return name;
}

int Paper::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }
    return TIE; // there is no UID less than this->UID hence always will be a tie
}