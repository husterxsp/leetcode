#include <iostream>
#include <vector>
using namespace std;

// 一些问题，
// 用if 不对
// while (i > 0  && nums[i] == nums[i - 1]) i++;  也不对
// ...
void find(vector<vector<int>>& allSubsets, vector<int>& subset, vector<int>& nums, int start) {
    for (int i = start; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        allSubsets.push_back(subset);
        find(allSubsets, subset, nums, i + 1);
        subset.pop_back();
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> subset;
    if (nums.empty()) return allSubsets;
    allSubsets.push_back(subset);
    sort(nums.begin(), nums.end());
    find(allSubsets, subset, nums, 0);
    return allSubsets;
}

int main() {
    vector<int> nums = {1, 2, 2};
    subsetsWithDup(nums);
    return 0;
}
