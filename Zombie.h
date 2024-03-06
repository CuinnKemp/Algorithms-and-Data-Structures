#ifndef ZOMBIE
#define ZOMBIE

#include <unordered_set>
#include <string>

#include "Move.h"

class Zombie : public Move {
private:
    int UID = 8;
    std::string name = "Zombie";
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

        // loses to robot (uid 5) and ninja (uid 7)
        std::unordered_set<int> losesTo({5,7});
        if (losesTo.find(Opponent) != losesTo.end()){
            return LOSER;
        }
        return WINNER;
    }

};

#endif // ZOMBIE