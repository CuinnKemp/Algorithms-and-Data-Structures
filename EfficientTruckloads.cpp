#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize){
    // if num crates can fit on truck return 1 (i.e. 1 truck)
    if (numCrates <= loadSize){
        return 1;
    }

    // check if loadsize has changed
    if (this->cLoadSize == loadSize){
        // check if there is an entry in the dp
        if (this->dp.find(numCrates) != this->dp.end()){
            // if there is return it
            return this->dp[numCrates];
        }
    } else{
        // if it has then change load size and clear the dp
        this->cLoadSize = loadSize;
        this->dp.clear();
    }

    // initialise a res variable
    int res = 0;

    // return the sum of both trees
    if (numCrates%2) { // is odd
        res += numTrucks(numCrates/2, loadSize);
        res += numTrucks((numCrates/2)+1, loadSize); // +1 due to integer division rounding down
    } else { // is even
        res = (2 * numTrucks(numCrates/2, loadSize));
    }

    // set the dp to be this value
    this->dp[numCrates] = res;
    //return the result
    return res;
}