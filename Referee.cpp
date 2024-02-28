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
    if (move == 'R') return 0;
    if (move == 'P') return 1;
    if (move == 'S') return 2;

    return -1;
}

Player* Referee::refGame(Player * player1, Player * player2){
    
    char res1 = player1->makeMove(), res2 = player2->makeMove();

    int move1 = move2Number(res1), move2 = move2Number(res2);

    int winner =  this->resultSquare[move1][move2];
    if (winner == 1) return player1;
    else if (winner == 2) return player2;
    return nullptr;
}

