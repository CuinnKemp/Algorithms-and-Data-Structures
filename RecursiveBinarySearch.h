#ifndef RECURSIVEBINARYSEARCH
#define RECURSIVEBINARYSEARCH

#include <vector>


class RecursiveBinarySearch {
private:
    bool search_helper(std::vector<int>& list, int value, int low, int high);
public:
    bool search(std::vector<int> list, int value);
};



#endif // RECURSIVEBINARYSEARCH