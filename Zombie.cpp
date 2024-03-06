#include "Zombie.h"

int Zombie::getUID(){
    return UID;
}

std::string Zombie::getName(){
    return name;
}

int Zombie::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }

    // loses to robot (uid 5) and ninja (uid 7)
    std::unordered_set<int> losesTo({5,7});
    if (losesTo.find(Opponent) != losesTo.end()){
        return LOSER;
    }
    return WINNER;
}