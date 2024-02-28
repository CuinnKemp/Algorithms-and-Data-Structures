#ifndef PLAYER
#define PLAYER

#include <bits/stdc++.h>
using namespace std;


// abstract class that has children Human and Computer
class Player {
public:
    virtual char makeMove() = 0;
    virtual string getName() = 0;
};

#endif // PLAYER