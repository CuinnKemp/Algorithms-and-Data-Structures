#include <bits/stdc++.h>
using namespace std;

#include "Player.h"
#include "Referee.h"

Referee::Referee(){

}

Player* Referee::refGame(Player * player1, Player * player2){
    
    char res1 = player1->makeMove(), res2 = player2->makeMove();

    switch (res1){
        case 'R':
            switch (res2){
                case 'R':
                    return nullptr;
                case 'P':
                    return player2;

                case 'S':
                    return player1;
            }

        case 'P':
            switch (res2){
                case 'R':
                    return player1;

                case 'P':
                    return nullptr;

                case 'S':
                    return player2;
            }

        case 'S':
            switch (res2){
                case 'R':
                    return player2;

                case 'P':
                    return player1;

                case 'S':
                    return nullptr;
            }
    }

    return nullptr;
}

