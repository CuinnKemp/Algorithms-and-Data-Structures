#include <string>
#include <iostream>

#include "Reverser.h"

int main(){
    Reverser R;

    int value;
    std::cin >> value;
    std::cout << R.reverseDigit(value) << std::endl;

    // std::string characters;
    // std::cout << R.reverseString(characters) << std::endl;
}