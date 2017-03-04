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
bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] < nums[right]) {
            if (target >= nums[mid] && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else if (nums[mid] > nums[right]) {
            if (target >= nums[left] && target <= nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            right--;
        }
    }
    return false;
}

int main () {
    vector<int> nums = {1, 3};
    int target = 3;
    cout << search(nums, target) << endl;
    return 0;
}
