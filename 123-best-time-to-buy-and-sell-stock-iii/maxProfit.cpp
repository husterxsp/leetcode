#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

// 思路：
// wrong answer：[1,2,4], expected: 3, output: 4
//
// assume: ret[0] > ret[1]
// int maxProfit(vector<int>& prices) {
//     if(!prices.size()) return 0;
//     int min = prices[0], ret[2] = {0}, cur = 0;
//     for (int i = 1;i < prices.size();i++) {
//         cur = prices[i] - min;
//         if (cur > ret[0]) {
//             ret[1] = ret[0];
//             ret[0] = cur;
//         }
//         else if (cur > ret[1]) {
//             ret[1] = cur;
//         }
//         if (cur < 0) {
//             min = prices[i];
//         }
//     }
//     return ret[0] + ret[1];
// }

// 参考网上解析：divide and conquer (既然是限制只能是两次交易，有啥算法跟2有关，分治，二分。。。)
// 动规，是不是就是保存已计算过的值?
int maxProfit(vector<int>& prices) {
    if (!prices.size()) return 0;

    // minNum: 左边开始最小的
    // maxNum: 右边开始最大的
    // 思路: 以中间某个值为分界，左右两边各一次买入卖出, 先用一个数组记录左边的，然后再从右边遍历，
    // 复杂度：时间O(n), 空间O(n)
    int n = prices.size(), minNum = prices[0], maxNum = prices[n - 1], ret = 0;

    vector<int> leftMax(n, 0);
    for (int i = 1; i < prices.size(); i++) {
        minNum = min(prices[i], minNum);
        leftMax[i] = max(prices[i] - minNum, ret);
        ret = leftMax[i];
    }

    for (int i = n - 1; i >= 0 ; i--) {
        maxNum = max(prices[i], maxNum);
        ret = max(leftMax[i] + maxNum - prices[i], ret);
    }
    return ret;
}

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
    return 0;
}
