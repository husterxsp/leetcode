/**
    搞不定。。没头绪
    参考网上解答：定义二维dp数组dp[i][j]
    i: 给定整数n
    k: 给定整数k
    http://www.cnblogs.com/grandyang/p/7111385.html
*/

/*
    递推公式dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1]
    如下解法超时
*/
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int modulo = 1000000007;

        dp[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (int m = 0; m <= k; m++) {
                    if (m - j >= 0 && m - j <= k) {
                        dp[i][m] += dp[i - 1][m - j];
                        dp[i][m] %= modulo;
                    }
                }
            }
        }

        return dp[n][k];
    }
};

/*
    改进: dp[n][k] = dp[n][k-1] + dp[n - 1][k] - dp[n - 1][k - n]
    待理解细看
*/
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int modulo = 1000000007;

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % modulo;
                if (j - i >= 0) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + modulo) % modulo;
                }
            }
        }
        return dp[n][k];
    }
};
