#ifndef EFFICIENTTRUCKLOADS
#define EFFICIENTTRUCKLOADS

#include <unordered_map>

class EfficientTruckloads{
private:
    // change load size checker
    int cLoadSize;

    // create memoisation unoredered_map
    std::unordered_map<int,int> dp;
public:
    int numTrucks(int numCrates, int loadSize);
};


#endif //EFFICIENTTRUCKLOADS