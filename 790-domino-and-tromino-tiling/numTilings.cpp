参考discuss, 想到了dp, 但是不清楚怎么解

找规律题...

class Solution {
public:
    int numTilings(int N) {
        vector<long> dp(1005);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= N; i++) {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= 1000000007;
        }
        return dp[N];
    }
};
