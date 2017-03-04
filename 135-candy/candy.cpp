#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 思路：一看就是贪婪，但是。。。怎么写代码。。
int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (!n) return 0;
    vector<int> candy(n + 1, 0);
    candy[0] = 1;
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
        else {
            candy[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
            candy[i] = candy[i + 1] + 1;
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += candy[i];
    }
    return ret;
}

int main(){
    vector<int> ratings = {4, 2, 3, 4, 1};
    cout << candy(ratings) << endl;
    return 0;
}
