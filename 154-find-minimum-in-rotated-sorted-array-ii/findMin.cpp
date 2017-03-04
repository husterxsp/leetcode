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
// 在做binary sesarch的时候，循环条件怎么设定？start < end 还是start <= end,
// 还有怎么缩放边界，end = mid 还是end = mid - 1
int findMin(vector<int>& nums) {
    int ret = 0;
    int left = 0, right = nums.size() - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        }
        else if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right--;
        }
    }
    return nums[left];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl;
    return 0;
}
