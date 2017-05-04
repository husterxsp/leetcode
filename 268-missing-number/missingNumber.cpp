#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
/**
    一开始想，既然少了一个数，那么循环一遍，找到相邻的两个数差值是2就好
    但是情况比较多，无法AC...

    1. 数学公式求和
    2. 位运算
    3. 先排序，再二分查找
*/
int missingNumber(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for (auto num : nums) {
        sum += num;
    }
    return 0.5 * n * (n + 1) - sum;
}

int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        res ^= (i + 1);
        res ^= nums[i];
    }
    return res;
}

int main () {
    vector<int> nums = {1, 0};
    cout << missingNumber(nums) << endl;
    return 0;
}
