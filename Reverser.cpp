#include <cmath>
#include <iostream>
using namespace std;

#include "Reverser.h"

// int Reverser::reverseDigit(int value){
//     std::string reveresed_value_string = reverseString(std::to_string(value));
//     return std::stoi(reveresed_value_string);
// }


int Reverser::reverseDigit(int value){
    int log = log10(value);
    if (log < 1) return value; 
    int last_digit = value - (value/10)*10;
    int res = reverseDigit(value/10);
    return last_digit * pow(10,log) + res;
}



std::string Reverser::reverseString(std::string characters){
    if (characters.size() == 0){
        return "";
    }
    return reverseString(characters.substr(1)) + characters[0];
}