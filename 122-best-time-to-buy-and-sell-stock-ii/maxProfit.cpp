#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

// 贪婪
// 思路：每天都会买进卖出
int maxProfit(vector<int>& prices) {
    if(!prices.size()) return 0;
    int min, ret, cur;
    min = prices[0], ret = 0, cur = 0;
    for(int i = 1;i < prices.size();i++){
        cur = prices[i] - min;
        if(cur > 0){
            ret += cur;
        }
        min = prices[i];
    }
    return ret;
}

int main(){
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
    return 0;
}
