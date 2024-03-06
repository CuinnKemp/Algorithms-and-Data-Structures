#include "Player.h"
#include "Referee.h"
#include "MoveFactory.h"

Referee::Referee(){
    this->move_factory = new MoveFactory;
}

Player* Referee::refGame(Player * player1, Player * player2){
    // collect the players moves
    Move* move1 = move_factory->string_to_move(player1->makeMove());
    Move* move2 = move_factory->string_to_move(player2->makeMove());

    int output = -1;
    if (move1->getUID() >= move2->getUID()){
        output = move1->isWinner(move2->getUID());
        if (output ==  WINNER) return player1;
        if (output == TIE) return nullptr;
        return player2;
    } else {
        output = move2->isWinner(move1->getUID());
        if (output ==  WINNER) return player2;
        if (output == TIE) return nullptr;
        return player1;
    }
    
    return nullptr;
}

