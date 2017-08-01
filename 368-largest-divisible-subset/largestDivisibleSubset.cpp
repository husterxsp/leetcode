/**
    小数对大数取余一定不为0，所以只考虑大数对小数
    先排序
    pre[i] 表示位置i之后第一个能被nums[i]整除的数的位置
    max_len 最长的子集的长度
    max_pos 最长的子集的起始位置
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), max_len = 0, max_pos = 0;
        vector<int> dp(n, 0), pre(n, 0), ret;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (max_len < dp[i]) {
                max_len = dp[i];
                max_pos = i;
            }
        }

        for (int i = 0; i < max_len; i++) {
            ret.push_back(nums[max_pos]);
            max_pos = pre[max_pos];
        }

        return ret;
    }
};
