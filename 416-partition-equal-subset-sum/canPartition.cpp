#include <iostream>
#include <vector>
#include <numeric>

/**
 完全搞不定。。。
 */
using namespace std;
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // 注意这个j从小到大和从大到小还不一样
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp.back();
}
int main() {
    vector<int> nums = {1,5,11,5};
    cout << canPartition(nums) << endl;
    return 0;
}
