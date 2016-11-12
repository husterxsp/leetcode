#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(!prices.size()) return 0;
    int min = prices[0], ret[2] = {0}, cur = 0;
    for(int i=1;i<prices.size();i++){
        cur = prices[i] - min;
        // ret[0] > ret[1]
        if(cur > ret[0]){
            ret[1] = ret[0];
            ret[0] = cur;
        }else if(cur > ret[1]) {
            ret[1] = cur;
        }
        if(cur < 0){
            min = prices[i];
        }
    }
    return ret[0]+ret[1];
}

int main(){
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a);
    return 0;
}
