#ifndef PLAYER
#define PLAYER

#include <string>

// abstract class that has children Human and Computer
class Player {
public:
    virtual std::string makeMove() = 0;
    virtual std::string getName() = 0;
};

#endif // PLAYER