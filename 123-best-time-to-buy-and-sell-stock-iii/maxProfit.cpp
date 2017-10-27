#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

/**
思路1，暴力求解，超时 197/198
help函数来自 T121
*/
int help(vector<int>& prices) {
    if (prices.empty()) return 0;
    int minPrice = prices[0], ret = 0;
    for (int i = 1; i < prices.size(); i++) {
        ret = max(ret, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return ret;
}
int maxProfit(vector<int>& prices) {
    int ret = 0;
    for (int i = 0; i < prices.size(); i++) {
        ret = max(ret, help(vector<int>(prices.begin(), prices.begin() + i)) +
                help(vector<int>(prices.begin() + i, prices.end())));
    }
    return ret;
}

// // 参考网上解析：divide and conquer (既然是限制只能是两次交易，有啥算法跟2有关，分治，二分。。。)
/**
基于上面的暴力解进行优化，主要是 计算[0, j+1]的很多工作在[0,j]中已经计算过，考虑怎么解决重复计算。
数组 left[i] 记录了price[0..i]的最大profit，
数组 right[i]记录了price[i..n]的最大profit。
*/

int maxProfit(vector<int>& prices) {
    if (!prices.size()) return 0;

    int n = prices.size(), min = prices[0], max = prices[n - 1], ret = 0;

    vector<int> left(n), right(n);
    for (int i = 1; i < n; i++) {
        min = min(prices[i], min);
        left[i] = max(left[i - 1], prices[i] - minNum);
    }

    for (int i = n - 2; i >= 0 ; i--) {
        max = max(max, prices[i]);
        right[i] = max(right[i + 1], max - prices[i]);

        ret = max(ret, left[i] + right[i]);
    }
    return ret;
}

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
    return 0;
}
