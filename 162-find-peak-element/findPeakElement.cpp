#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main () {
    vector<int> nums = {1,2,3,1};
    cout << findPeakElement(nums) << endl;
    return 0;
}
