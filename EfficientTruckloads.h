#ifndef EFFICIENTTRUCKLOADS
#define EFFICIENTTRUCKLOADS

#include <unordered_map>

class EfficientTruckloads{
private:
    int cLoadSize;
    std::unordered_map<int,int> dp;
public:
    int numTrucks(int numCrates, int loadSize);
};


#endif //EFFICIENTTRUCKLOADS