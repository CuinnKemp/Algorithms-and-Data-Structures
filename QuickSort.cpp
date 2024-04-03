#include "QuickSort.h"


std::vector<int> QuickSort::sort(std::vector<int> list){
    if (list.size() <= 1) return list;

    std::vector<int> left, right;
    for (int i = 1; i < list.size(); i++){
        if (list[i] <= list[0]){
            left.push_back(list[i]);
        } else {
            right.push_back(list[i]);
        }
    }

    left = sort(left);
    right = sort(right);
    left.push_back(list[0]);
    for (auto i : right){
        left.push_back(i);
    }
    return left;
}