#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
/**
    超时。。。想了好久其他的数据结构好像也都没法解
*/
int minMoves(vector<int>& nums) {
    int ret = 0, n = nums.size(),
        max_value = *max_element(nums.begin(), nums.end()), min_value = *min_element(nums.begin(), nums.end());
    while (max_value != min_value) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            nums[i] += max_value - min_value;
        }
        ret += max_value - min_value;
        max_value = *max_element(nums.begin(), nums.end()), min_value = *min_element(nums.begin(), nums.end());
    }
    return ret;
}
/**
    参考网上思路，将加1转换为最大值减1。easy题也这么难A...
*/
int minMoves(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0), min_value = *min_element(nums.begin(), nums.end());
    return sum - min_value * nums.size();
}

int main() {
    vector<int> nums{1,2,3,5};
    cout << minMoves(nums) << endl;
    return 0;
}
