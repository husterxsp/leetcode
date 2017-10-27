#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
/*
    参考：
    https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java
    https://discuss.leetcode.com/topic/26169/clean-java-dp-solution-with-comment
    注意K如果比较大，prices数组比较小的情况下，问题简化为T121。否则仍用动规效率比较低。

    dp(i,j) is the max profit for up to i transactions by time j (0<=i<=K, 0<=j<=T).

*/

int help(vector<int>& prices) {
    int ret = 0;
    for (int i = 1; i < prices.size(); i++)
        ret += max(prices[i] - prices[i - 1], 0);
    return ret;
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (k >= n / 2) return help(prices);

    vector<vector<int>> dp(k + 1, vector<int>(n));
    for (int i = 1; i <= k; i++) {
        int tmpMax = -prices[0];
        for (int j = 1; j < n; j++) {
            // 当前天有交易，则肯定是卖出，包含当天的最大利益是 当前的卖出 + 过去的一次买入 + (i-1)次交易
            dp[i][j] = max(dp[i][j - 1], prices[j] + tmpMax);
            // 记录 过去的一次买入 + (i-1)次交易 的最大值
            // 不太懂为啥 dp[i - 1][j] 也能A ?
            tmpMax = max(tmpMax, dp[i - 1][j - 1] - prices[j]);
        }
    }
    return dp[k][n - 1];
}

int main () {
    vector<int> prices = {6, 1, 3, 2, 4, 7};
    cout << maxProfit(10, prices) << endl;
    return 0;
}
