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
    MoveFactory();
    Move* string_to_move(std::string move);
};



#endif // MOVEFACTORY