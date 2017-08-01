/**
    思路：三个数两种情况，两个负数或者三个都是正数
    排序的解法O(nlogn)
    或者直接遍历一遍，遍历的过程中比较并保存最小的两个负数和最大的三个正数
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int product1 = nums[0] * nums[1] * nums.back();
        int product2 = (nums.end() - 2) * (nums.end() - 1) * nums.back();
        return max(product1, product2);
    }
};
