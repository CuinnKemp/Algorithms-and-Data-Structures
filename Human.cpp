#include <bits/stdc++.h>
using namespace std;

#include "Human.h"

// default constructor set name to "Human"
Human::Human(){
    this->name = "Human";
}

// set name to the provided value
Human::Human(string name){
    this->name = name;
}

// get humans input and return it
char Human::makeMove(){
    char res;
    cout << "Enter move:";
    cin >> res;

    return res;
}

// return the humans name
string Human::getName(){
    return this->name;
}