#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

// 思路：记录一个最小值min
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int minPrice = prices[0], ret = 0;
    for (int i = 1; i < prices.size(); i++) {
        ret = max(ret, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return ret;
}

int main(){
    vector<int> a = {};
    cout << maxProfit(a);
    return 0;
}
