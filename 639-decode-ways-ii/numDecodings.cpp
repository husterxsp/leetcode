class Solution {
public:
    int numDecodings(string s) {
        s = '0' + s;

        int n = s.size();
        vector<double> dp(n, 1);

        if (s[1] == '*') dp[1] = 9;
        else if (s[1] == '0') return 0;
        else dp[1] = 1;

        for (int i = 2; i < n; i++) {
            if (s[i] == '*') {
                dp[i] = 9 * dp[i - 1];
                if (s[i - 1] == '1') dp[i] += 9 * dp[i - 2];
                else if (s[i - 1] == '2') dp[i] += 6 * dp[i - 2];
                else if (s[i - 1] == '*') dp[i] += 15 * dp[i - 2];

                dp[i] = fmod(dp[i], 1000000007.0);
            }
            else if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') dp[i] = dp[i - 2];
                else if (s[i - 1] == '*') dp[i] = 2 * dp[i - 2];
                else return 0;

                dp[i] = fmod(dp[i], 1000000007.0);
            }
            else if (s[i] >= '1' && s[i] <= '6') {
                dp[i] = dp[i - 1];
                if (s[i - 1] == '1' || s[i - 1] == '2') dp[i] += dp[i - 2];
                else if (s[i - 1] == '*') dp[i] += 2 * dp[i - 2];

                dp[i] = fmod(dp[i], 1000000007.0);
            }
            else {
                dp[i] = dp[i - 1];
                if (s[i - 1] == '1') dp[i] += dp[i - 2];
                else if (s[i - 1] == '*') dp[i] += dp[i - 2];

                dp[i] = fmod(dp[i], 1000000007.0);
            }

        }
        return dp[n - 1];
    }
};
