#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>
#include <cstring>
#include <string.h>

using namespace std;
bool increasingTriplet(vector<int>& nums) {
    int i = INT_MAX, j = INT_MAX, k;
    for (auto k : nums) {
        if (k <= i) {
            i = k;
        }
        else if (k <= j) {
            j = k;
        }
        else {
            return true;
        }
    }
    return false;
}

int main () {
    vector<int> nums = {7, 1, 10, 3, 4};
    cout << increasingTriplet(nums) << endl;
    return 0;
}
