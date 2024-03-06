#ifndef NINJA
#define NINJA

#include <unordered_set>
#include <string>

#include "Move.h"

class Ninja : public Move {
private:
    int UID = 7;
    std::string name = "Ninja";
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

        // loses to monkey (uid 3) and robot (uid 4)
        std::unordered_set<int> losesTo({3,4});
        if (losesTo.find(Opponent) != losesTo.end()){
            return LOSER;
        }
        return WINNER;
    }

};

#endif // NINJA