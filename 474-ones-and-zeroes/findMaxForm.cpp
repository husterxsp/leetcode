/**
    动规？
    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);

    注意这题的字符串只能用一次，所以循环时放在外层？
    另外循环的时候i, j 从大到小也是为了字符串只用一次
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (auto str : strs) {
            int zeros = 0, ones = 0;
            for (auto c : str) {
                if (c == '0') zeros++;
                else ones++;
            }

            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
