#include <iostream>
#include <vector>

/**
动态规划
 */
using namespace std;
int search(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount < 0) return -1;
    // 如果访问过，直接返回
    if (dp[amount] != INT_MAX) return dp[amount];

    for (auto coin : coins) {
        int tmp = search(coins, amount - coin, dp);

        // 如果tmp是-1，则保持
        if (tmp >= 0) dp[amount] = min(dp[amount], tmp + 1);
    }

    // 对已经遍历到的amount要保存之后再返回
    return dp[amount] = dp[amount] == INT_MAX ? -1 : dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    // 此处初始化时如果初始化为amount+1，则可以避免INT_MAX+1溢出的情况
    vector<int> dp(amount + 1, INT_MAX);
    // 这个初始条件用于判断刚好能由某个coin组成的情况
    dp[0] = 0;
    return search(coins, amount, dp);
}

int main() {
    vector<int> coins = {186,419,83,408};
    cout << coinChange(coins, 6249) << endl;
    return 0;
}
