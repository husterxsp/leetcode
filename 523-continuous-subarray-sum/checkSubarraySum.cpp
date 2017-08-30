class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 2; j <= n; j++) {
                if (k == 0 && sum[j] - sum[i] == 0) return true;
                else if (k != 0 && (sum[j] - sum[i]) % k == 0) return true;
            }
        }
        return false;
    }
};
