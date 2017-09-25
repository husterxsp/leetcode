//  dp：[index, [difference, count]]
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ret = 0, n = A.size();
        if (n < 3) return 0;
        vector<unordered_map<int, int>> dp(n);

        for (int i = 2; i < n; i++) {
            for (int j = i - 1; j > 0; j--) {
                int diff = A[i] - A[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] = dp[j][diff] + 1;
                    ret += dp[i][diff];                    
                }

            }
        }
        return ret;
    }
};
