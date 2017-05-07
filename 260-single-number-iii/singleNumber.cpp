#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

/**
 参考解法：http://fisherlei.blogspot.com/2015/10/leetcode-single-number-iii-solution.html
 将数组分开

 */
using namespace std;
vector<int> singleNumber(vector<int>& nums) {
    int xorNums = 0;
    for (auto num : nums) {
        xorNums ^= num;
    }

    int index = 0;
    while ((xorNums>>index & 1) != 1) index++;

    int xorSecond = 0;
    for (auto num : nums) {
        if ((num>>index & 1) == 1) {
            xorSecond ^= num;
        }
    }

    vector<int> ret = {xorSecond, xorSecond^xorNums};

    return ret;
}

int main () {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    singleNumber(nums);
    return 0;
}
