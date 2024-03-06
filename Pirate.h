#ifndef PIRATE
#define PIRATE

#include <unordered_set>
#include <string>

#include "Move.h"

class Pirate : public Move {
private:
    int UID = 6;
    std::string name = "Pirate";
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

        // loses to monkey (uid = 4)
        std::unordered_set<int> losesTo({4});
        if (losesTo.find(Opponent) != losesTo.end()){
            return LOSER;
        }
        // not a tie or a loss so must be win
        return WINNER; 
    }

};

#endif // PIRATE