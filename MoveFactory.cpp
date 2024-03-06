#include "MoveFactory.h"
// move factory init
MoveFactory::MoveFactory(){
    // add all moves from Rock Paper Scissors
    moves_map["Rock"] = new Rock;
    moves_map["Paper"] = new Paper;
    moves_map["Scissors"] = new Scissors;

    // add all moves from Monkey Robot Pirate Ninja Zombie
    moves_map["Monkey"] = new Monkey;
    moves_map["Robot"] = new Robot;
    moves_map["Pirate"] = new Pirate;
    moves_map["Ninja"] = new Ninja;
    moves_map["Zombie"] = new Zombie;
}

// return the move using string as key
Move* MoveFactory::string_to_move(std::string move){
    return moves_map[move];
}