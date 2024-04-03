#include "RecursiveBinarySearch.h"


bool RecursiveBinarySearch::search(std::vector<int> list, int value){
    return search_helper(list, value, 0, list.size()-1);
}


bool RecursiveBinarySearch::search_helper(std::vector<int>& list, int value, int low, int high){
    if (low >= high){
        if (list[low] != value){
            return false;
        }
    }
    
    int mid = (low + high)/2;

    if (list[mid] == value){
        return true;
    } if (list[mid] > value){
        return search_helper(list, value, low, mid-1);
    } else {
        return search_helper(list, value, mid+1, high);
    }
}