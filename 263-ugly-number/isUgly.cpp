#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;

bool isUgly(int num) {
    if (num <= 0) return false;

    vector<int> arr = {2,3,5};
    int prev = num;
    while (num > 1) {
        for (int i = 0; i < arr.size(); i++) {
            if (num % arr[i] == 0) {
                num /= arr[i];
            }
        }
        if (num == prev) break;
        prev = num;
    }
    if (num == 1) return true;
    return false;
}

int main () {

    cout << isUgly(11) << endl;
    return 0;
}
