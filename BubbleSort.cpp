#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list){
    if (list.size() <= 1){
        return list;
    }

    bool hasSwapped = true;
    while (hasSwapped) {
        hasSwapped = false;
        for (int i = 1; i < list.size(); i++){
            if (list[i-1] > list[i]){
                int temp = list[i];
                list[i] = list[i-1];
                list[i-1] = temp;
                hasSwapped = true;
            }
        }
    }
    
    return list;
}