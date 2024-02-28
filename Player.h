#ifndef PLAYER
#define PLAYER

#include <bits/stdc++.h>
using namespace std;

class Player {
public:
    virtual char makeMove() = 0;
    virtual string getName() = 0;
};

#endif // PLAYER