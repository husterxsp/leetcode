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
// 一点坑：mid = (left + right) / 2;  四舍五入会取小，所以mid和right比较？
int findMin(vector<int>& nums) {
    int ret = 0;
    int left = 0, right = nums.size() - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return nums[left];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl;
    return 0;
}
