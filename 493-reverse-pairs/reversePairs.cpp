/*
    解法1：类归并排序
    参考：
    http://blog.csdn.net/crystal6918/article/details/53246730
    http://www.cnblogs.com/grandyang/p/6657956.html

*/
class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;

        int ret = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; i++) {
            // 注意此处如果写成 nums[i] > nums[j] * 2 则有乘法溢出的情况。
            // 改成除法后注意要用浮点数，用整数会有误差
            while (j <= right && nums[i] / 2.0 > nums[j]) j++;
            ret += j - mid - 1;
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

/*
    树状数组
*/
