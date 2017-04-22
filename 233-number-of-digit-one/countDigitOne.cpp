#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

int getNum(int k) {
    if (k == 1) return 1;
    return getNum(k - 1) * 9 + pow(10, k - 1);
}

int countDigitOne(int n) {
    int bit = 0, tmp = n;
    if (n <= 0) return 0;
    if (n <= 9) return 1;

    while (tmp > 9) {
        bit++;
        tmp /= 10;
    }

    int xx = pow(10, bit);

    if (tmp == 1) {
        return  n - xx + 1 + getNum(bit);
    }

    return getNum(bit) * (tmp - 1) + pow(10, bit) + countDigitOne(n - xx * tmp);
}

int main () {
//    cout << getNum(1) << endl;
    cout << countDigitOne(11) << endl;
    return 0;
}
