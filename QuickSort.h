#ifndef QUICKSORT
#define QUICKSORT
#include "Sort.h"

class QuickSort : public Sort {
private:
    void quickSort(std::vector<int>& list, low, high);
public:
    std::vector<int> sort(std::vector<int> list);
};

#endif // QUICKSORT

