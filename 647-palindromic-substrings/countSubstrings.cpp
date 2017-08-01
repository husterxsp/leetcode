/**
    动规，dp[i][j] 表示区间[i, j]的回文串个数。
    递推公式：
    aba  4
    aaa  6
    3 + 3 - 1 + 1 = 6
    2 + 2 - 1 + 1 = 4
    aaaa
    6 + 6 - 3 + 1 = 10
    abba
    4 + 4 - 3 + 1 = 6

    acbc
    3 + 4 - 2

    aa
    1 + 1 + 1

    a
    1

    aab : 4
    aba : 4
    aaba

    4 + 4 - 2

    思路：如上列了一些简单的字符串找规律。。。从而找到递推公式
*/
class Solution {
public:
    // i, j从1开始避免访问溢出
    // dp[i][j] 记录回文串个数，isPalindromic记录[i, j]是否是回文串
    // 本解法内存超出限制，参考下面改进
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)), isPalindromic(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i > 0; i--) {
            dp[i][i] = 1;
            isPalindromic[i][i] = 1;
            for (int j = i + 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                if (s[i - 1] == s[j - 1] && (i == j - 1 || isPalindromic[i + 1][j - 1]) ) {
                    dp[i][j]++;
                    isPalindromic[i][j] = 1;
                }
            }
        }
        return dp[1][n];
    }
};

/**
    以上解法内存超出限制，改进如下
    dp[0] 对应上面循环中的dp[i]
    dp[1] 对应上面循环中的dp[i + 1]
    isPalindromic同理
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n + 2, 0)), isPalindromic(2, vector<int>(n + 2, 0));

        for (int i = n; i > 0; i--) {
            dp[0][i] = 1;
            isPalindromic[0][i] = 1;
            for (int j = i + 1; j <= n; j++) {
                dp[0][j] = dp[0][j - 1] + dp[1][j] - dp[1][j - 1];
                if (s[i - 1] == s[j - 1] && (i == j - 1 || isPalindromic[1][j - 1]) ) {
                    dp[0][j]++;
                    isPalindromic[0][j] = 1;
                }
            }
            dp[1] = dp[0];
            isPalindromic[1] = isPalindromic[0];

            fill(dp[0].begin(), dp[0].end(), 0);
            fill(isPalindromic[0].begin(), isPalindromic[0].end(), 0);
        }
        return dp[1][n];
    }
};
