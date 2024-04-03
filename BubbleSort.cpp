#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list){
    // if the list size is less than or equal to one return the list
    if (list.size() <= 1){
        return list;
    }

    // create break condition
    bool hasSwapped = true;
    
    // while the hasSwapped value is true 
    while (hasSwapped) {
        // set hasSwapped to false
        hasSwapped = false;

        // itterate over list
        for (int i = 1; i < list.size(); i++){
            // if a swap needs to occur
            if (list[i-1] > list[i]){
                std::swap(list[i-1], list[i]);

                // set flag to true
                hasSwapped = true;
            }
        }
    }
    
    // return the sorted list
    return list;
}