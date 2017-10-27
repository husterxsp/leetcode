class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int tmpMax = INT_MIN, n = prices.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = max(dp[i - 1], tmpMax + prices[i]);
            tmpMax = max(tmpMax, dp[i - 1] - prices[i] - fee);
        }
        return dp[n - 1];
    }
};
