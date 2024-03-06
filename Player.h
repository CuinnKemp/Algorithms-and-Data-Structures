#ifndef PLAYER
#define PLAYER

#include <string>
#include "MoveFactory.h"
// abstract class that has children Human and Computer
class Player {
public:
    MoveFactory move_factory;
    virtual Move* makeMove() = 0;
    virtual std::string getName() = 0;
};

#endif // PLAYER