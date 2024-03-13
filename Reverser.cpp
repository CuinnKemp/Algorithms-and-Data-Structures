#include <cmath>

#include "Reverser.h"

// int Reverser::reverseDigit(int value){
//     std::string reveresed_value_string = reverseString(std::to_string(value));
//     return std::stoi(reveresed_value_string);
// }
// 1234 => 4321
// x = val % 10 givrd 

// 1234
// 4 123
// 43 12
// 432 1
// 4321


int Reverser::reverseDigit(int value){
    // invalid input check
    if (value < 0) return -1;

    // get number of digits
    int digits = log10(value);

    // if only 1 digit (digits = 0) break recursion
    if (digits == 0) return value; // return the current value

    // the last digit will be the mod of the current value
    int last_digit = value%10;
    // recur on the value divided by 10
    int res = reverseDigit(value/10);
    
    // append the last_digit value to the number
    return last_digit * pow(10,digits) + res;
}




std::string Reverser::reverseString(std::string characters){
    // if the size of the characters is 0
    if (characters.size() == 0){
        // exit loop
        return "";
    }

    // recur on second char to last char and append the previous first value
    return reverseString(characters.substr(1)) + characters[0];
}