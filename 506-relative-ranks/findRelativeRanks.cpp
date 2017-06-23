#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
/**
    这题可忽略
*/
using namespace std;
struct compareByKey {
    bool operator()(const int& k1, const int& k2) const {
        return k1 > k2;
    }
};
vector<string> findRelativeRanks(vector<int>& nums) {
    int n = nums.size();
    vector<string> ret(n), tmp{"Gold Medal", "Silver Medal", "Bronze Medal"};

    map<int, int, compareByKey> myMap;
    for (int i = 0; i < n; i++) myMap[nums[i]] = i;

    int i = 0;
    for (auto itor : myMap) {
        if (i < 3) ret[itor.second] = tmp[i];
        else ret[itor.second] = to_string(i + 1);
        i++;
    }
    return ret;
}

int main() {
    vector<int> nums = {5,3,1,4,2};
    findRelativeRanks(nums);
    return 0;
}
