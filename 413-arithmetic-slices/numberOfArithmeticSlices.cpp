#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
/**
 理解题意，求长度大于等于3的等差数列的个数
 */
int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size(), ret = 0, cur = 0;
    for (int i = 2; i < n; i++) {
        if (A[i] + A[i - 2] == 2 * A[i - 1]) {
            cur++;
            ret += cur;
        }
        else {
            cur = 0;
        }
    }
    return ret;
}

int main() {
    vector<int> A = {1,2,3,4,5};
    cout << numberOfArithmeticSlices(A) << endl;
    return 0;
}
