// easy
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return 0;

        vector<int> sum(n, nums[0]);
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];

        if (sum[n - 1] - sum[0] == 0) return 0;

        for (int i = 1; i < n; i++) {
            if (sum[i - 1] == sum[n - 1] - sum[i]) return i;
        }

        return -1;
    }
};
