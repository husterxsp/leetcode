#include <iostream>
#include <vector>

/**
解法1：O(n^2)
解法2：
*/
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), ret = 0;
    if (n <= 1) return n;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main() {
    vector<int> nums = {2, 2};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
