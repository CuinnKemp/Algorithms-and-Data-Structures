#include <iostream>
#include <string>
#include <list>

#include "LinkedList.h"
#include "BigNumCalc.h"



int main(){
    BigNumCalc b1;

    std::string s1 = "100", s2 = "50";

    std::list<int> n1 = b1.buildBigNum(s1);

    std::list<int> n2 = b1.buildBigNum(s2);

    for (auto i : n1){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i : n2){
        std::cout << i << " ";
    }
    std::cout << std::endl;


    std::list<int> list = b1.mul(n1, n2);
    for (auto i : list){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}