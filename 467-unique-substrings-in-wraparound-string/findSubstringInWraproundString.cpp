/*
    maxLen: 表示当前 p[i]位置向前连续字符串的长度
    m[p[i]]: 表示已遍历过的以字符p[i]为终点的向前连续字符串的最大长度
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size(), maxLen = 1;
        if (!n) return 0;

        vector<int> dp(n, 1);
        unordered_map<char, int> m;

        m[p[0]] = 1;

        for (int i = 1; i < n; i++) {
            if ((p[i] - p[i - 1] == 1) || (p[i - 1] == 'z' && p[i] == 'a')) {
                maxLen = maxLen + 1;
            }
            else {
                maxLen = 1;
            }
            dp[i] = dp[i - 1] + max(0, maxLen - m[p[i]]);
            m[p[i]] = max(m[p[i]], maxLen);
        }
        return dp[n - 1];
    }
};
