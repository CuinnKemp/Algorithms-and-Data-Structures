#ifndef ROBOT
#define ROBOT

#include <unordered_set>
#include <string>

#include "Move.h"

class Robot : public Move {
private:
    int UID = 5;
    std::string name = "Robot";
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

        // loses to Monkey
        std::unordered_set<int> losesTo({4});
        if (losesTo.find(Opponent) != losesTo.end()){
            return LOSER;
        }
        return TIE;
    }

};

#endif // ROBOT