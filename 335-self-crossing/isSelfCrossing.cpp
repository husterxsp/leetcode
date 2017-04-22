#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>
#include <cstring>
#include <string.h>

using namespace std;
/**
情况1：
    x(1)
    ┌───┐
x(2)│   │ x(0)
    └───┼──>
    x(3)│

情况2：
      x(1)
    ┌──────┐
    │      │x(0)
x(2)│      ^
    │      │x(4)
    └──────│
      x(3)
情况3：
      x(1)
    ┌──────┐
    │      │x(0)
x(2)│    <-│────——│
    │         x(5)│x(4)
    └───────────——│
        x(3)

*/
// i从3开始，至少得有四个才会出现相交的情况
bool isSelfCrossing(vector<int>& x) {
    for (int i = 3; i < x.size(); i++) {
        if ((x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) ||
            (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) ||
            (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 1] <= x[i - 3] && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3]))
            return true;
    }
    return false;
}

int main () {
    vector<int> x = {1, 1, 1, 1};
    cout << isSelfCrossing(x) << endl;
    return 0;
}
