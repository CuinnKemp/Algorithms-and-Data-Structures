#ifndef REFEREE
#include "MoveFactory.h"
#include "Player.h"


class Referee {
private: 
    MoveFactory* move_factory;
public:
    // sets up the referee variable resultSquare
    Referee();

    // returns the winning player from a game of rock paper scissors
    Player* refGame(Player * player1, Player * player2);
};

#endif // REFEREE