#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k){
    std::priority_queue<int> pq;

    for (auto i : values){
        if (pq.size() >= k){
            if (-pq.top() < i){
                pq.push(-i);
                pq.pop();
            }
        } else {
            pq.push(-i);
        }
    }
    if (pq.size() == k)
        return -pq.top();

    return -1;
}