#ifndef COMPUTER
#define COMPUTER

#include <bits/stdc++.h>
using namespace std;

#include "Player.h"

class Computer : public Player{
public:
    char makeMove();
    string getName();
};

#endif // COMPUTER