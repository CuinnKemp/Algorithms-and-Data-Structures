#ifndef REFEREE
#define REFEREE
#include <bits/stdc++.h>
using namespace std;

#include "Player.h"


class Referee {
private:
    // used to get the value without needing to do multiple comparisons
    vector<vector<int>> resultSquare;
    // converts the char 'R'/'P'/'S' to an integer value 
    int move2Number(char move);
public:
    // sets up the referee variable resultSquare
    Referee();

    // returns the winning player from a game of rock paper scissors
    Player* refGame(Player * player1, Player * player2);
};

#endif // REFEREE