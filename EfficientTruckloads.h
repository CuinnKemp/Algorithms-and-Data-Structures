#ifndef TRUCKLOADS
#define TRUCKLOADS

#include <unordered_map>

class Truckloads{
private:
    int cLoadSize;
    std::unordered_map<int,int> dp;
public:
    int numTrucks(int numCrates, int loadSize);
};


#endif //TRUCKLOADS