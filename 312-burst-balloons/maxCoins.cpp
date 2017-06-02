#include <iostream>
#include <vector>
#include <map>

using namespace std;
/**
 不会。。还不太懂。。待再看
 http://www.cnblogs.com/grandyang/p/5006441.html
 https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations
 https://discuss.leetcode.com/topic/84687/java-top-down-and-bottom-up-dp-solutions/2
 */
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; len++) {
        for (int left = 1; left <= n - len + 1; left++) {

            int right = left + len - 1;
            for (int k = left; k <= right; k++) {
                int tmp = nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right];

                dp[left][right] = max(dp[left][right], tmp);
            }
        }
    }
    return dp[1][n];
}
int main () {
    vector<int> nums = {3,6,7,8};
    cout << maxCoins(nums) << endl;
    return 0;
}
