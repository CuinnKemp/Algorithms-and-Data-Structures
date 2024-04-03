#include "BubbleSort.h"

#include "QuickSort.h"

#include "RecursiveBinarySearch.h"

#include <vector>
#include <iostream>
#include <string>


int main(){
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> list;
    std::string num;
    for (int i = 0; i < input.length(); i++){
        if (input[i] >= '0' && input[i] <= '9'){
            num.push_back(input[i]);
        } else if (num.size() > 0){
            list.push_back(stoi(num));
            num = "";
        } else if (num.size() == 0 && input[i] == '-'){
            num = "-";
        }
    }
    if (input.back() >= '0' && input.back() <= '9'){
        list.push_back(stoi(num));
        num = "";
    }
    
    QuickSort sorter;
    RecursiveBinarySearch searcher;

    std::vector<int> sortedList = sorter.sort(list);
    bool oneFound = searcher.search(sortedList, 1);

    if (oneFound){
        std::cout << "true ";
    } else {
        std::cout << "false ";
    }
    for (auto i : sortedList){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


