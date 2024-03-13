#include "EfficientTruckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize){
    // if num crates can fit on truck return 1 (i.e. 1 truck)
    if (numCrates <= loadSize){
        return 1;
    }

    if (this->cLoadSize == loadSize){
        if (this->dp.find(numCrates) != this->dp.end()){
            return this->dp[numCrates];
        }
    } else{
        this->cLoadSize = loadSize;
    }

    int res = 0;

    // return the sum of both trees
    if (numCrates%2) { // is odd
        res += numTrucks(numCrates/2, loadSize);
        res += numTrucks((numCrates/2)+1, loadSize); // +1 due to integer division rounding down
    } else { // is even
        res = (2 * numTrucks(numCrates/2, loadSize));
    }
    
    dp[numCrates] = res;
    return res;
}