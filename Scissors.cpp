#include "Scissors.h"

int Scissors::getUID(){
    return UID;
}

std::string Scissors::getName(){
    return name;
}

int Scissors::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }
    
    std::unordered_set<int> losesTo({2});

    if (losesTo.find(Opponent) != losesTo.end()){
        return LOSER;
    } else {
        return WINNER;
    }
}