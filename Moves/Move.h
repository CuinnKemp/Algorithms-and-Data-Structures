#ifndef MOVE
#define MOVE

#define INVALID -1
#define WINNER 0
#define TIE 1
#define LOSER 2

class Move {
public:
    virtual int getUID() = 0;

    virtual int isWinner(int Opponent) = 0;
};

#endif // MOVE