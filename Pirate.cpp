#include "Pirate.h"

int Pirate::getUID(){
    return UID;
}

std::string Pirate::getName(){
    return name;
}

int Pirate::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }

    // doesnt lose to anything less than self so always wins
    std::unordered_set<int> losesTo({});
    if (losesTo.find(Opponent) != losesTo.end()){
        return LOSER;
    }
    // not a tie or a loss so must be win
    return WINNER; 
}