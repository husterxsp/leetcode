/**
    思路：先找到最长的公共子序列
    DP求解
*/
class Solution {
public:
    int help(string word1, string word2) {
        int m = word1.size(), n = word2.size(), ret = 0;
        if (m == 0 || n == 0) return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * help(word1, word2);
    }
};
