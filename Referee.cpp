#include <bits/stdc++.h>
using namespace std;

#include "Player.h"
#include "Referee.h"

Referee::Referee(){
    // row player 1 move
    // col player 2 move
    this->resultSquare = {
        {0,2,1},
        {1,0,2},
        {2,1,0},
    };
}

int Referee::move2Number(char move){
    // convert the char to an integer used for the result square accessing
    if (move == 'R') return 0;
    if (move == 'P') return 1;
    if (move == 'S') return 2;

    // -1 invalid input has been encountered
    return -1;
}

Player* Referee::refGame(Player * player1, Player * player2){
    // collect the players moves
    int move1 = move2Number(player1->makeMove()), move2 = move2Number(player2->makeMove());

    // get the winners value
    int winner =  this->resultSquare[move1][move2];
    
    // if winner is 1 return p1 if 2 return p2 if 0 return nullptr
    if (winner == 1) return player1;
    else if (winner == 2) return player2;
    return nullptr;
}

