#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
    暴力解...TLE...
*/
vector<int> rotateFunc(vector<int> A, int k) {
    int n = A.size();
    vector<int> tmp(A.begin() + n - k, A.end());

    A.erase(A.begin() + n - k, A.end());
    A.insert(A.begin(), tmp.begin(), tmp.end());
    return A;
}
int maxRotateFunction(vector<int>& A) {
    int n = A.size(), ret = INT_MIN;
    if (!n) return 0;

    for (int k = 0; k < n; k++) {
        int f = 0;
        vector<int> rotateArr = rotateFunc(A, k);
        for (int i = 0; i < n; i++) f += i * rotateArr[i];
        ret = max(ret, f);
    }
    return ret;
}
/**
    AC
*/
int maxRotateFunction(vector<int>& A) {
    int n = A.size();
    if (!n) return 0;
    vector<int> sum(n, A[0]);
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + A[i];

    int normalF = 0;
    for (int i = 0; i < n; i++) normalF += i * A[i];

    int ret = normalF;
    for (int k = 1; k < n; k++) {
        int curF = normalF + sum[n - k - 1] * k - (sum[n - 1] - sum[n - k - 1]) * (n - k);
        ret = max(ret, curF);
    }
    return ret;
}

int main() {
    vector<int> A{-2147483648,-2147483648};
    cout << maxRotateFunction(A) << endl;
    return 0;
}
