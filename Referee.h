#ifndef REFEREE
#define REFEREE
#include <bits/stdc++.h>
using namespace std;

#include "Player.h"


class Referee {
private:
    vector<vector<int>> resultSquare;
    int move2Number(char move);
public:
    Referee();
    Player* refGame(Player * player1, Player * player2);
};

#endif // REFEREE