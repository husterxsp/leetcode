#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/**
 注意外层while循环的终止条件
 */
int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0, ret = 0, left = 0, right = 0, n = nums.size();
    while (left < n && right < n) {
        while (sum < s && right < n) {
            sum += nums[right++];
        }
        while (sum - nums[left] >= s) {
            sum -= nums[left++];
        }
        if (sum < s) break;

        int len = right - left;
        ret = ret == 0 ? len : min(ret, len);

        sum -= nums[left++];
    }
    return ret;
}
// 简化版
int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0, ret = INT_MAX, left = 0, right = 0, n = nums.size();
    while (left < n && right < n) {
        while (sum < s && right < n) {
            sum += nums[right++];
        }
        while (sum >= s) {
            ret = min(ret, right - left);
            sum -= nums[left++];
        }
    }
    return ret == INT_MAX ? 0 : ret;
}
int main () {
    vector<int> nums = {1,1};
    cout << minSubArrayLen(3, nums) << endl;
    return 0;
}
