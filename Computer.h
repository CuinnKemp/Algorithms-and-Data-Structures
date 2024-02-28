#ifndef COMPUTER
#define COMPUTER

#include <bits/stdc++.h>
using namespace std;

#include "Player.h"

class Computer : public Player{
public:
    // implement the virtual functions from player
    char makeMove();
    string getName();
};

#endif // COMPUTER