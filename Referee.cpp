#include <bits/stdc++.h>
using namespace std;

#include "Player.h"
#include "Referee.h"
#include "Moves/MoveFactory.h"

Referee::Referee(){
    // row player 1 move
    // col player 2 mo
}

Player* Referee::refGame(Player * player1, Player * player2){
    // collect the players moves
    Move* move1 = char2Move(player1->makeMove());
    Move* move2 = char2Move(player2->makeMove());

    if (move1 == nullptr || move2 == nullptr){
        cout << "INVALID INPUT" << endl;
        return nullptr;
    }

    int output = move1->isWinner(move2->getUID());

    if (output == INVALID){
        output = move2->isWinner(move1->getUID());
        delete move1, move2;
        if (output ==  WINNER) return player2;
        if (output == TIE) return nullptr;
        return player1;
    }

    delete move1, move2;
    if (output ==  WINNER) return player1;
    if (output == TIE) return nullptr;
    return player2;
}

