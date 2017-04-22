#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {

    vector<int> primeI(primes.size(), 0);
    vector<int> ugly = {1};

    while (ugly.size() < n) {
        int m = ugly[primeI[0]] * primes[0], mIndex = 0;
        for (int i = 1; i < primeI.size(); i++) {
            int cur = ugly[primeI[i]] * primes[i];
            if (cur < m) {
                m = cur;
                mIndex = i;
            }
        }
        primeI[mIndex]++;

        if (m == ugly.back()) continue;
        ugly.push_back(m);
    }

    return ugly.back();
}

int main () {
    vector<int> primes = {2, 7, 13, 19};
    cout << nthSuperUglyNumber(12, primes) << endl;
    return 0;
}
