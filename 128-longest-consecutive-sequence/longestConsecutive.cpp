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

// 这题看的我也是一脸蒙蔽。。数据结构不熟。。O(n)
// 题目要求O(n)时间复杂度，那不能排序，快排也只能nlogn，只能hash
// http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-consecutive-sequence.html
// http://zh.cppreference.com/w/cpp/container/set
int longestConsecutive(vector<int>& nums) {
    int ret = 0;
    unordered_set<int> mySet;
    for (int i = 0; i < nums.size(); i++) {
        mySet.insert(nums[i]);
    }
    for (int i = 0; i < nums.size(); i++) {
        int curLen = 0;
        int curNum = nums[i];

        while (mySet.count(curNum)) {
            mySet.erase(curNum);
            curLen++;
            curNum++;
        }
        curNum = nums[i] - 1;
        while (mySet.count(curNum)) {
            mySet.erase(curNum);
            curLen++;
            curNum--;
        }
        ret = max(ret, curLen);
    }
    return ret;
}

int main() {
    vector<int> num = {400, 1, 2, 3, 4};
    cout << longestConsecutive(num) << endl;
    return 0;
}
