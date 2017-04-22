#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>

/**
    1. 之前没用过priority_queue 优先队列。。
    2. 重点是后面的排序，要求时间复杂度优于O(nlogn), 快排时间复杂度最坏是O(n^2)不符合
    3. 
*/
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ret;
    unordered_map<int, int> myMap;
    for (auto num: nums) myMap[num]++;

    priority_queue<pair<int, int>> pQueue;

    for (auto pair: myMap) pQueue.push({pair.second, pair.first});
    for (int i = 0; i < k; i++) {
        ret.push_back(pQueue.top().second);
        pQueue.pop();
    }
    return ret;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    topKFrequent(nums, 2);
    return 0;
}
