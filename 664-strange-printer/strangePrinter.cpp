/*
    A不动。。
    参考：https://discuss.leetcode.com/topic/100212/c-29ms-dp-solution
    discuss讨论说跟546 remove boxes基本一样
*/
class Solution {
public:
    int help(string s, int l, int r, vector<vector<int>>& dp) {
        if (l > r) return 0;
        if (dp[l][r]) return dp[l][r];

        dp[l][r] = help(s, l, r - 1, dp) + 1;

        for (int i = l; i < r; i++) {
            if (s[i] == s[r]) dp[l][r] = min(dp[l][r], help(s, l, i, dp) + help(s, i + 1, r - 1, dp));
        }
        return dp[l][r];
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        return help(s, 0, n - 1, dp);
    }
};
