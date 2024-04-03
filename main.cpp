#include "BubbleSort.h"

#include "QuickSort.h"

#include <vector>
#include <iostream>


int main(){
    std::vector<int> list = {1, 3, 5, 4, -5, 100, 7777, 2014};

    BubbleSort b1;
    QuickSort q1;

    std::vector<int> sortedList = b1.sort(list);

    for (auto i : sortedList){
        std::cout << i << " ";  
    }
    std::cout << std::endl;

    sortedList = q1.sort(list);

    for (auto i : sortedList){
        std::cout << i << " ";  
    }
    std::cout << std::endl;
}


