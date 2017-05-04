#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> myMap;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        myMap[nums[i]] = i;
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        int tar = target - nums[i];
        if (myMap.count(tar)) {
            ret.push_back({i, myMap[tar]});
            break;
        }
    }
    return ret;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    twoSum(nums, 13);
    return 0;
}
