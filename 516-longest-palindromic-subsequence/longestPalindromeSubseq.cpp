/**
    思路：参考T486 Predict the Winner
    关键是写出动态规划的递推公式
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if (s[i] == s[j]) {
                    if (j == i + 1) dp[i][j] = 2;
                    else dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
            }
        }
        return dp[0][n - 1];
    }
};
/**
    解法二：使用一维dp数组，还没搞懂。。。
*/
