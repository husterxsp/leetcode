#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
/*
 时间 O(logN) 空间 O(k^2) ?
 每5个数会产生一个0。
 试想1*2*3*4*5*6*7*8*9*10*11，前5个数中有一个2一个5，相乘有一个0，后5个数中有一个10，又有一个0。
 以此类推，每5个数会有一个0。
 */
int trailingZeroes(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n / 5;
        n /= 5;
    }
    return ret;
}

int main () {
    cout << trailingZeroes(1000) << endl;
    return 0;
}
