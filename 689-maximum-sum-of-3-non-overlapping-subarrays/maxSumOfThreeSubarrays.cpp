/**
    思路：一开始想的暴力解，即O(n^3)时间复杂度的3层循环，但肯定不过，然后有一个dp数组
    将复杂度降到O(n^2),但其实可以用两个数组，将复杂度降到O(n)

    sum[i]:从i开始的k个数和
    dp[i]:从i开始到结束的区间内，dp[i]对应位置开始的k个数和最大
    时间复杂度O(n^2)

    参考优化到O(n)：https://discuss.leetcode.com/topic/105577/c-java-dp-with-explanation-o-n
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1);

        sum[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        for (int i = 1; i < n - k + 1; i++) {
            sum[i] = sum[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        vector<int> ret(3);
        vector<int> dp(n);

        dp[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            if (sum[i] > sum[dp[i + 1]]) dp[i] = i;
            else dp[i] = dp[i + 1];
        }

        int pre = 0, cur = 0;
        for (int i = 0; i < n - 3 * k + 1; i++) {
            for (int j = i + k; j < n - 2 * k + 1; j++) {
                int tmp = sum[i] + sum[j] + sum[dp[j + k]];
                if (tmp > pre) {
                    pre = tmp;
                    ret = vector<int>{i, j, dp[j + k]};
                }
            }
        }
        return ret;
    }
};
