#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            nums.erase(nums.begin() + i);
            nums.push_back(0);
            i--;
            n--;
        }
    }
}

int main () {
    vector<int> nums = {0, 0, 1, 2, 0, 10};
    moveZeroes(nums);
    return 0;
}
