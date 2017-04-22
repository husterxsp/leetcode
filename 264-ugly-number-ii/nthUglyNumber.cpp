#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;

int nthUglyNumber(int n) {
    //2, 3, 5
    int i2 = 0, i3 = 0, i5 = 0;
    vector<int> ugly = {1};

    while (ugly.size() < n) {
        int m1 = ugly[i2] * 2;
        int m2 = ugly[i3] * 3;
        int m3 = ugly[i5] * 5;
        int minNum = min(m1, min(m2, m3));

        if (minNum == m1) i2++;
        if (minNum == m2) i3++;
        if (minNum == m3) i5++;

        ugly.push_back(minNum);
    }

    return ugly.back();
}

int main () {
    cout << nthUglyNumber(1 ) << endl;
    return 0;
}
