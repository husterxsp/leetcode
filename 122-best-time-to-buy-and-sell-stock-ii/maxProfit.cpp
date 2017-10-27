#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

// 贪婪，注意题中写的 as many as啊
// 思路：每天都会买进卖出
int maxProfit(vector<int>& prices) {
    int ret = 0;
    for (int i = 1; i < prices.size(); i++)
        ret += max(prices[i] - prices[i - 1], 0);
    return ret;
}

int main(){
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
    return 0;
}
