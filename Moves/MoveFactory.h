#ifndef MOVEFACTORY
#define MOVEFACTORY

#include "Move.h"
#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"

Move* char2Move(char move){
    switch (move){
        case 'P':
            return new Paper;

        case 'R':
            return new Rock;
        
        case 'S':
            return new Scissors;

        default:
            return nullptr;
    }
}



#endif // MOVEFACTORY