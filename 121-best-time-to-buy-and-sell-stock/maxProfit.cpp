#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(!prices.size()) return 0;
    int min, ret, cur;
    min = prices[0], ret = 0, cur = 0;
    for(int i=1;i<prices.size();i++){
        cur = prices[i] - min;
        if(cur > ret){
            ret = cur;
        }
        if(cur < 0){
            min = prices[i];
        }
    }
    return ret;
}

int main(){
    vector<int> a = {7, 6, 4, 3, 1};
    cout << maxProfit(a);
    return 0;
}
