/**
    排序，O(nlogn) 时间复杂度
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 这两个reverse是为了解决[4,5,5,6]的情况
        reverse(nums.begin(), nums.begin() + (n + 1) / 2);
        reverse(nums.begin() + (n + 1) / 2, nums.end());

        for (int i = 1, j = (n + 1) / 2; j < n; i += 2, j++) {
            nums.insert(nums.begin() + i, nums[j]);
            nums.erase(nums.begin() + j + 1);
        }
    }
};

// 题目要求O(n)时间，O(1)空间
