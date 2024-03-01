#ifndef REFEREE
#define REFEREE
#include <bits/stdc++.h>
using namespace std;

#include "Player.h"


class Referee {
public:
    // sets up the referee variable resultSquare
    Referee();

    // returns the winning player from a game of rock paper scissors
    Player* refGame(Player * player1, Player * player2);
};

#endif // REFEREE