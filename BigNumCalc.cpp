#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString){
        // assume the string is exclusivly digits 0-9
        std::list<int> bigNum;
        for (int i = numString.size()-1; i > -1; i--){
            bigNum.push_front(numString[i] - '0');
        }
        return bigNum;
    }


std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    std::list<int> * longer, * shorter;

    if (num1.size() >= num2.size()){
        longer = &num1;
        shorter = &num2;
    } else {
        longer = &num2;
        shorter = &num1;
    }

    auto longIt = longer->rbegin();
    auto shortIt = shorter->rbegin();

    int carry = 0;
    while (shortIt != shorter->rend()){
        *longIt += *shortIt + carry;
        carry = 0;
        if (*longIt >= 10){
            carry = 1;
            *longIt -= 10;
        }

        shortIt++;
        longIt++;
    }

    while (carry > 0 && longIt != longer->rend()){
        *longIt += carry;
        carry = 0;
        if (*longIt >= 10){
            carry = 1;
            *longIt -= 10;
        }

        longIt++;
    }
    if (carry > 0 && longIt == longer->rend()){
        longer->push_front(carry);
    }


    return *longer;
}

// num 1 > num 2 always
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    auto oneIt = num1.rbegin();
    auto twoIt = num2.rbegin();

    int carry = 0;
    while (twoIt != num2.rend()){
        *oneIt -= *twoIt + carry;
        carry = 0;
        if (*oneIt < 0){
            carry = 1;
            *oneIt += 10;
        }

        twoIt++;
        oneIt++;
    }

    while (carry > 0 && oneIt != num1.rend()){
        *oneIt -= carry;
        carry = 0;
        if (*oneIt < 0){
            carry = 1;
            *oneIt += 10;
        }

        oneIt++;
    }

    while (num1.size() > 1 && num1.front() == 0){
        num1.pop_front();
    }

    return num1;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    std::list<int> largerHold, *larger, *smaller;
    if (num1.size() >= num2.size()){
        larger = &num1;
        smaller = &num2;
    } else {
        larger = &num2;
        smaller = &num1;
    }

    largerHold = *larger;
    
    
    while (smaller->size() > 1 || (smaller->size() == 1 && smaller->front() != 1)){
        *larger = this->add(*larger, largerHold);
        *smaller = this->sub(*smaller, {1});
    }

    return *larger;
}