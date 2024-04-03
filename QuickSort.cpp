#include "QuickSort.h"
#include <iostream>

// inplace QuickSort
std::vector<int> QuickSort::sort(std::vector<int> list){
    // call the quickSort helper function
    quickSort(list, 0, list.size()-1); // list passed by reference

    // return the list (as it was passed by reference the helper sorts the list given to it)
    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high){
    // recursion base case
    if (low >= high){
        return;
    }

    // if at least 3 elements within the range then use the third value otherwise use first
    if (high-low >= 3){
        std::swap(list[low], list[low+2]);
    }
    

    // init left and right pointers to count the values greater and less than the pivot value
    int left = low+1, right = high;
    while (left <= right){
        // while the value at index left is less than the pivot value
        while (left <= high && list[left] <= list[low]){
            // increment the left counter
            left++;
        }

        // while the value at index right is greater than the pivot value
        while (right >= low && list[right] > list[low]){
            // decrement the right value
            right--;
        }

        // check whether swap should occur
        if (left < right){
            // swap the values
            std::swap(list[left], list[right]);
            // incrment left pointer
            left++;
            // decrement right pointer
            right--;
        }

    }

    // swap the pivot value to  the desired location
    std::swap(list[low], list[right]);

    // call quicksort on the left and right partitions
    return  quickSort(list, low, right-1), quickSort(list, right+1, high);;
}


// first attempt (wild space complexity lol)
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