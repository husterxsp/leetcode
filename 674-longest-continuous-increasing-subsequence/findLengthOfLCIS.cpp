class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), ret = 1, cur = 1;
        if (!n) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                ret = max(ret, cur);
                cur = 1;
            }
            else {
                cur++;
            }
        }
        return max(ret, cur);
    }
};
