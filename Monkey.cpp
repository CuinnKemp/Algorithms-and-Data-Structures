#include "Monkey.h"
#include "Move.h"

int Monkey::getUID(){
    return UID;
}

std::string Monkey::getName(){
    return name;
}

int Monkey::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }
    return TIE; // there is no UID less than this->UID hence always will be a tie
}