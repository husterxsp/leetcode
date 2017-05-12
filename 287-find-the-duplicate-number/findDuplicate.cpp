#include <iostream>
#include <vector>

using namespace std;

/**
 一开始想的是先排序nlogn，然后再遍历。。但是题目要求不能修改数组
 二分搜索解法：http://www.cnblogs.com/grandyang/p/4843654.html
 */
int findDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (auto num : nums) {
            if (num <= mid) count++;
        }
        if (count > mid) right = mid;
        else left = mid + 1;
    }
    return left;
}
/**
快慢双指针解法：http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
*/
int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0, ret = 0;
    while (1) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) break;
    }
    while (1) {
        slow = nums[slow];
        ret = nums[ret];
        if (ret == slow) break;
    }
    return ret;
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5};
    cout << findDuplicate(nums) << endl;
    return 0;
}
