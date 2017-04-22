#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;
// 虽然也能AC，但是复杂度是 O(n^2)
// 拆分为三个数的解法。。实在没有这个数学知识啊。。。
int integerBreak(int n) {
    vector<int> ret = {0, 1, 1, 2, 4, 6};
    for (int i = 6; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= i / 2; j++) {
            tmp = max(tmp, max(ret[j], j) * max(ret[i - j], i - j));
        }
        ret.push_back(tmp);
    }
    return ret[n];
}


int main() {
    cout << integerBreak(8) << endl;
    return 0;
}
