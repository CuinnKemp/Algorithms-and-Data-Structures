#include <iostream>
#include<string>

#include "Human.h"
#include "MoveFactory.h"

// default constructor set name to "Human"
Human::Human(){
    this->name = "Human";
}

// set name to the provided value
Human::Human(std::string name){
    this->name = name;
}

// get humans input and return it
Move* Human::makeMove(){
    std::string res;
    std::cout << "Enter move:";
    std::cin >> res;

    return this->move_factory.string_to_move(res);
}

// return the humans name
std::string Human::getName(){
    return this->name;
}