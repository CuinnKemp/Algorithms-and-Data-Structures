#include "QuickSort.h"
#include <iostream>


// std::vector<int> QuickSort::sort(std::vector<int> list){
//     // recursive base case (singular element)
//     if (list.size() <= 1) return list;

//     if (list.size() >= 3) 
//         std::swap(list[0], list[2]); // use third value

//     // construct left and right vectors
//     std::vector<int> left, right;
//     // left is values that will sit to the left of the pivot and right values to the right;
//     for (int i = 1; i < list.size(); i++){
//         // if the pivot is greater than the value (will sit to the left)
//         if (list[i] <= list[0]){
//             left.push_back(list[i]);
//         } else { // the value is greater than the pivot (will sit to the right)
//             right.push_back(list[i]);
//         }
//     }

//     // sort the left and right vectors and merge them
//     left = sort(left);
//     right = sort(right);
//     left.push_back(list[0]);
//     left.insert(left.end(), right.begin(), right.end());
//     return left;
// }



std::vector<int> QuickSort::sort(std::vector<int> list){
    quickSort(list, 0, list.size()-1); // list passed by reference
    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high){
    if (low >= high){
        return;
    }
    if (high-low >= 3){
        std::swap(list[low], list[low+2]);
    }

    int left = low+1, right = high;
    while (left <= right){
        while (left <= high && list[left] <= list[low]){
            left++;
        }

        while (right >= low && list[right] > list[low]){
            right--;
        }

        if (left < right){
            std::swap(list[left], list[right]);
            left++;
            right--;
        }

    }

    std::swap(list[low], list[right]);

    quickSort(list, low, right-1);
    quickSort(list, right+1, high);
    return;
}