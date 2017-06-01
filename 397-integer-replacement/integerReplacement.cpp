#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
/**
    思路1：
    先判断是不是2的幂次，再判断是2的多少倍
    第一次A的时候没注意n+1会溢出
    思路2：递归
*/
int integerReplacement(int n) {
    int ret = 0;
    long nCopy = (long)n;
    while (nCopy > 1) {
        ret++;
        if (nCopy % 2 == 0) nCopy >>= 1;
        else {
            long n1 = nCopy + 1, n2 = nCopy - 1;
            int c1 = 0, c2 = 0;
            bitset<33> b1(n1), b2(n2);
            if (b2.count() == 1) {
                nCopy -= 1;
                continue;
            }
            if (b1.count() == 1) {
                nCopy += 1;
                continue;
            }

            while (n1 % 2 == 0) {
                n1 /= 2;
                c1++;
            }
            while (n2 % 2 == 0) {
                n2 /= 2;
                c2++;
            }
            if (c1 > c2) {
                ret += c1;
                nCopy = n1;
            }
            else if (c2 > c1) {
                ret += c2;
                nCopy = n2;
            }
            else {
                nCopy = min(n1, n2);
                ret += c1;
            }
        }
    }
    return ret;
}

int main() {
    cout << integerReplacement(3) << endl;
    return 0;
}
