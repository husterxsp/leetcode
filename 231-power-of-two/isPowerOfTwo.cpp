#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
bool isPowerOfTwo(int n) {
    int match = 1, tmp = n, byte = 0;
    // 注意负数的情况。。。 -2147483648
    if (n < 0) return false;
    while (tmp > 0) {
        tmp >>= 1;
        byte++;
    }
    match = 1 << --byte;
    match ^= n;

    if (match == 0) return true;
    return false;
}
int main () {
    cout << isPowerOfTwo(2147483647) << endl;
    return 0;
}
