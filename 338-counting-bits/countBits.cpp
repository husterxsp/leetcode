#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>
#include <cstring>
#include <string.h>

using namespace std;
// 直接用bitset函数
vector<int> countBits(int num) {
    vector<int> ret;
    for (int i = 0; i <= num; i++) {
        ret.push_back(bitset<32>(i).count());
    }
    return ret;
}

// 找规律，[2^i, 2^i+1)
vector<int> countBits(int num) {
    if (num == 0) return {0};
    vector<int> ret = {0, 1};

    int i = 2, k = 2;
    while (i <= num) {
        int t = (pow(2, k) - pow(2, k - 1)) / 2;
        for (i = pow(2, k - 1); i < pow(2, k); i++) {
            if (i > num) break;
            if (i < pow(2, k - 1) + t) {
                ret.push_back(ret[i - t]);
            }
            else {
                cout << i - t << endl;
                ret.push_back(ret[i - t] + 1);
            }
        }
        k++;

    }
    return ret;
}
/**
 另外，判断一个数是2的指数幂的快捷方法？i&(i - 1) 原理嘞？
 二进制中只有一个1，并且1后面跟了n个0； 因此问题可以转化为判断1后面是否跟了n个0就可以了。
 http://www.cnblogs.com/grandyang/p/5294255.html
 ----
 这种找规律题。。让我怎么办。。
*/

int main () {
    countBits(5);
    return 0;
}
