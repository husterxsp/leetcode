/**
    [start, end] 表示需要排序的区间
    start = -1 表示暂时还不需要排序
    minNum, maxNum分别表示当前[start, end]区间的最小值和最大值
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), maxNum = INT_MIN, minNum = INT_MAX, start = -1, end = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i] || maxNum > nums[i]) {
                if (start == -1) start = i - 1;
                end = i;
            }
            if (start >= 0) {
                minNum = min(minNum, nums[i]);
                maxNum = max(maxNum, nums[i - 1]);
            }
            while (start > 0 && nums[i] < nums[start - 1]) {
                start--;
                minNum = nums[start];
            }
        }
        return start == -1 ? 0 : end - start + 1;
    }
};
