#ifndef MONKEY
#define MONKEY

#include <string>

#include "Move.h"

class Monkey : public Move {
private:
    int UID = 4;
    std::string name = "Monkey";

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
        return TIE; // there is no UID less than this->UID hence always will be a tie
    }

};

#endif // MONKEY