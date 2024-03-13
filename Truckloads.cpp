#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize){
    // if num crates can fit on truck return 1 (i.e. 1 truck)
    if (numCrates <= loadSize){
        return 1;
    }

    // return the sum of both trees
    if (numCrates%2) { // is odd
        int res = 0;
        res += numTrucks(numCrates/2, loadSize);
        res += numTrucks((numCrates/2)+1, loadSize); // +1 due to integer division rounding down
        return res;
    } else { // is even
        return (2 * numTrucks(numCrates/2, loadSize));
    }
}