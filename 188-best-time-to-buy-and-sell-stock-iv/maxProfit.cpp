#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
/*  贪婪
    思路：每天都会买进卖出
    wrong answer [6,1,3,2,4,7] 2
*/

int maxProfit(int k, vector<int>& prices) {
    int min = 0, n = prices.size(), ret = 0;
    vector<int> profit(n, 0);

    if(!n) return 0;
    min = prices[0];
    for (int i = 1; i < n; i++) {
        profit[i] = prices[i] - min;
        min = prices[i];
    }
    sort(profit.begin(), profit.end());
    for (int i = n - 1; i >= 0 && i >= n - k; i--) {
        if (profit[i] <= 0) break;
        ret += profit[i];
    }
    return ret;
}

int main () {
    vector<int> prices = {6, 1, 3, 2, 4, 7};
    cout << maxProfit(10, prices) << endl;
    return 0;
}
