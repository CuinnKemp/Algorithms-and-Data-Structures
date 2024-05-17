#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k){
    std::priority_queue<int> pq;

    for (auto i : values){
        pq.push(i);
    }

    while (!pq.empty() && k > 0){
        pq.pop();
        k--;
        if (k == 0){
            return pq.top();
        }
    }
    return -1;
}