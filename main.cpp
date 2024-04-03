#include "BubbleSort.h"

#include "QuickSort.h"

#include "RecursiveBinarySearch.h"

#include <vector>
#include <iostream>
#include <string>


int main(){
    // get input from user
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
    
    // innit a sorter and searcher object
    BubbleSort sorter;
    RecursiveBinarySearch searcher;

    // sort the list
    std::vector<int> sortedList = sorter.sort(list);

    // check if one is present in array
    bool oneFound = searcher.search(sortedList, 1);

    // output result of search function
    if (oneFound){
        std::cout << "true ";
    } else {
        std::cout << "false ";
    }

    // output the sorted list
    for (auto i : sortedList){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


