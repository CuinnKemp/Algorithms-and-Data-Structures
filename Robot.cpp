#include "Robot.h"

int Robot::getUID(){
    return UID;
}

std::string Robot::getName(){
    return name;
}

int Robot::isWinner(int Opponent){
    if (Opponent > this->UID){
        return INVALID; // invalid Opponent UID
    } else if (Opponent == this->UID){
        return TIE; // tie
    }

    // loses to Monkey
    std::unordered_set<int> losesTo({4});
    if (losesTo.find(Opponent) != losesTo.end()){
        return LOSER;
    }
    return TIE;
}