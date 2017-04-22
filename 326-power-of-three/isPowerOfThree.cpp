#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
// 解法1, 循环除
bool isPowerOfThree(int n) {
    while (n && n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

int main () {
    vector<int> primes = {2, 7, 13, 19};
    cout << nthSuperUglyNumber(12, primes) << endl;
    return 0;
}
