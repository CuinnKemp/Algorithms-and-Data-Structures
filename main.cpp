#include <iostream>
using namespace std;

#include "Player.h"
#include "Referee.h"

#include "Computer.h"
#include "Human.h"

int main() {
    Player *p1 = new Human("Bill"), *p2 = new Computer();

    Referee * referee = new Referee();

    string result = "It's a Tie";

    Player* winner = referee->refGame(p1, p2);
    if (winner != nullptr){
        result = winner->getName() + " Wins";
    }
    
    cout << result << endl;

    return 0;
}
