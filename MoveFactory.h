#ifndef MOVEFACTORY
#define MOVEFACTORY

#include <unordered_map>
#include <string>

#include "Move.h"

#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"

#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

class MoveFactory{
private:
    std::unordered_map<std::string, Move*> moves_map;

public:
    MoveFactory(){
        moves_map["Rock"] = new Rock;
        moves_map["Paper"] = new Paper;
        moves_map["Scissors"] = new Scissors;

        moves_map["Monkey"] = new Monkey;
        moves_map["Robot"] = new Robot;
        moves_map["Pirate"] = new Pirate;
        moves_map["Ninja"] = new Ninja;
        moves_map["Zombie"] = new Zombie;
    }
    Move* string_to_move(std::string move){
        return moves_map[move];
    }

    ~MoveFactory(){
        for (auto pair : moves_map){
            delete pair.second;
        }
    }
};



#endif // MOVEFACTORY