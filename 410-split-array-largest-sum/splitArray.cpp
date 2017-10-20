/**
    dp[start][m - 1]：表示从start位置到nums数组的末尾，分成m个子数组，对应的最小的 子数组和的最大值。
*/
class Solution {
public:
    int help(vector<int>& nums, int m, int start, vector<vector<int>>& dp, vector<int> sumArr, int n) {
        if (m == 1) return sumArr[n] - sumArr[start];
        if (dp[start][m - 1] != -1) return dp[start][m - 1];

        int ret = INT_MAX;
        for (int i = start; i <= n - m; i++) {

            int sum = sumArr[i + 1] - sumArr[start];

            ret = min(ret, max(sum, help(nums, m - 1, i + 1, dp, sumArr, n)));
        }
        return dp[start][m - 1] = ret;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sumArr(n + 1);
        for (int i = 1; i <= n; i++) {
            sumArr[i] = sumArr[i - 1] + nums[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return help(nums, m, 0, dp, sumArr, n);
    }
};
