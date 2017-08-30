class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0, pos = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                if (i == 0) nums[i] = nums[i + 1];
                else {
                    if (nums[i + 1] >= nums[i - 1]) nums[i] = nums[i - 1];
                    else nums[i + 1] = nums[i];
                }
            }
            if (cnt > 1) return false;
        }
        return true;
    }
};
