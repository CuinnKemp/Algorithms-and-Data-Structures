#include <iostream>

#include "Player.h"
#include "Referee.h"

#include "Computer.h"
#include "Human.h"

int main() {
    // init p1 and p2
    Player *p1 = new Human("Bill"), *p2 = new Human("Jeff");

    // init referee
    Referee * referee = new Referee();

    // init default output in result
    std::string result = "It's a Tie";

    // get winner
    Player* winner = referee->refGame(p1, p2);
    // if the winner is not a nullptr
    if (winner != nullptr){
        // set result to winners name
        result = winner->getName() + " Wins";
    }
    
    // output result
    std::cout << result << std::endl;

    return 0;
}
