#include "Ninja.h"

// implement getUID
int Ninja::getUID(){
    return UID;
}

// implement getName
std::string Ninja::getName(){
    return name;
}

// implement is winner
int Ninja::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }

    // loses to monkey (uid 3) and robot (uid 4)
    std::unordered_set<int> losesTo({3,4});
    if (losesTo.find(Opponent) != losesTo.end()){
        return LOSER;
    }
    return WINNER;
}