#ifndef HUMAN
#define HUMAN

#include <bits/stdc++.h>
using namespace std;

#include "Player.h"

class Human : public Player{
private:
    string name;
public:
    Human();
    Human(string name);

    char makeMove();
    string getName();
};

#endif // HUMAN