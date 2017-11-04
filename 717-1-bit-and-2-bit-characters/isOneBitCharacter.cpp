class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bits.insert(bits.begin(), 0);

        int n = bits.size();

        vector<int> dp(n, 1);
        dp[1] = bits[1] == 0;

        for (int i = 2; i < n - 1; i++) {
            if (bits[i] == 0) {
                dp[i] = dp[i - 1];
                if (bits[i - 1] == 1) {
                    dp[i] = dp[i] || dp[i - 2];
                }
            }
            else {
                if (bits[i - 1] == 0) dp[i] = false;
                else {
                    dp[i] = dp[i - 2];
                }
            }
        }
        return dp[n - 2];
    }
};
