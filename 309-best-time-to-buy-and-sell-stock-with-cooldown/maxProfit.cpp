/**
    参考网上解答:
    所以以下解法的递推式表示没有 “买买”，”卖卖”这种连续的情况？

    最后返回的是卖，因为如果最后一个可以买，那一定也可以卖，卖显然获利更多

    卖之前必须先有个买？所以在只有一个元素的情况下也返回0？

    参考：https://www.hrwhisper.me/leetcode-best-time-to-buy-and-sell-stock-with-cooldown/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> buy(n), sell(n);

        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);

        sell[1] = max(0, -prices[0] + prices[1]);

        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[n - 1];
    }
};
