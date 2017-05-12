#include <iostream>
#include <cmath>
#include <vector>

/**
 异或运算 模2和？
 */
using namespace std;
int getSum(int a, int b) {
    if (b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return getSum(sum, carry);
}

int main() {
    cout << getSum(1, -2) << endl;
    return 0;
}
