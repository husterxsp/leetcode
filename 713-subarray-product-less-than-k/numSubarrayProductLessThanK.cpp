class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ret = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= nums[j];
                if (product < k) ret++;
                else break;
            }
        }
        return ret;
    }
};
