#include "Monkey.h"
#include "Move.h"

// implement getUID virtual function
int Monkey::getUID(){
    return UID;
}

// implement getName virtual function
std::string Monkey::getName(){
    return name;
}

// implement isWinner virtual function
int Monkey::isWinner(int Opponent){
    // there is no UID lower than Monkey
    if (Opponent > this->UID){
        // if greater return invalid
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){ // opponent is same type
        return TIE; // tie
    }
    // default return
    return TIE; // there is no UID less than this->UID hence always will be a tie
}