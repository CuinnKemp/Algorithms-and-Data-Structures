#include <bits/stdc++.h>
using namespace std;

#include "Human.h"

Human::Human(string name){
    this->name = name;
}

char Human::makeMove(){
    char res;
    cout << "Enter move:";
    cin >> res;

    return res;
}

string Human::getName(){
    return this->name;
}