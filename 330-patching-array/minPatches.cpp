#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
// 以后凡是这种数字操作的，都得注意下是否会溢出啊啊啊。。
int minPatches(vector<int>& nums, int n) {
    int ret = 0, i = 0;
    long maxNum = 1;
    while (maxNum <= n) {
        if (i < nums.size() && nums[i] <= maxNum) {
            maxNum += nums[i++];
        }
        else {
            maxNum *= 2;
            ret++;
        }
    }
    return ret;
}

int main () {
    vector<int> nums = {1, 2, 31, 33};
    cout << minPatches(nums, 2147483647) << endl;
    return 0;
}
