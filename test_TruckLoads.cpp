#include <iostream>

#include "Truckloads.h"


int main(){
    Truckloads T;
    int numCrates, loadSize;
    std::cout << "numCrates = ";
    std::cin >> numCrates;

    std::cout << "loadSize = ";
    std::cin >> loadSize;

    // test a bunch of inputs such as those on website

    std::cout << "required trucks = " << T.numTrucks(numCrates, loadSize) << std::endl;
}