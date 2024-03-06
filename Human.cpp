#include <iostream>
#include<string>

#include "Human.h"

// default constructor set name to "Human"
Human::Human(){
    this->name = "Human";
}

// set name to the provided value
Human::Human(std::string name){
    this->name = name;
}

// get humans input and return it
std::string Human::makeMove(){
    std::string res;
    std::cout << "Enter move:";
    std::cin >> res;

    return res;
}

// return the humans name
std::string Human::getName(){
    return this->name;
}