// 超时。。。
class Solution {
public:
    int help(int amount, vector<int>& coins, int pos, int n, map<vector<int>, int>& myMap) {
        if (myMap.find({amount, pos}) != myMap.end()) return myMap[{amount, pos}];

        int ret = 0;
        for (int i = pos; i < n; i++) {
            if (coins[i] > amount) break;
            if (coins[i] == amount) {
                ret++;
                break;
            }
            else {
                ret += help(amount - coins[i], coins, i, n, myMap);
            }
        }
        return myMap[{amount, pos}] = ret;
    }
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;

        map<vector<int>, int> myMap;
        sort(coins.begin(), coins.end());

        return help(amount, coins, 0, coins.size(), myMap);
    }
};

// 参考网上解: http://blog.csdn.net/zshouyi/article/details/73699155
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);

        dp[0] = 1;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
