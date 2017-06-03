#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/**
    递归解，效率有点低
*/
int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    if (!n) return 0;
    if (n == 1) {
        // 如果nums[0]==0 则需要返回2
        if (S == nums[0] && S == -nums[0]) return 2;
        if (S == nums[0] || S == -nums[0]) return 1;
    }

    int back = nums.back(), ret = 0;
    nums.pop_back();
    ret = findTargetSumWays(nums, S + back) + findTargetSumWays(nums, S - back);
    nums.push_back(back);
    return ret;
}
/**
优化，dp数组保存已计算过的
*/
int search(vector<int> nums, int S, vector<unordered_map<int, int>> &dp) {
    int n = nums.size();
    if (!n) return S == 0;
    if (dp[n].find(S) != dp[n].end()) return dp[n][S];

    int back = nums.back(), ret = 0;
    nums.pop_back();
    ret = search(nums, S + back, dp) + search(nums, S - back, dp);

    return dp[n][S] = ret;
}
int findTargetSumWays(vector<int>& nums, int S) {
    vector<unordered_map<int, int>> dp(nums.size() + 1);
    return search(nums, S, dp);
}
/**
    非递归
*/

int main(){
    vector<int> nums{0,1};
    cout << findTargetSumWays(nums, 1) << endl;
    return 0;
}
