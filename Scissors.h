#ifndef SCISSORS
#define SCISSORS

#include<unordered_set>

#include "Move.h"

class Scissors : public Move {
private:
    int UID = 3;
    std::string name = "Scissors";
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
        
        std::unordered_set<int> losesTo({2});

        if (losesTo.find(Opponent) != losesTo.end()){
            return LOSER;
        } else {
            return WINNER;
        }
    }

};



#endif // SCISSORS