class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> sum(n + 1, nums[0]);
        // sum[i] 表示[0, i）的区间和
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];

        double ret = INT_MIN;
        for (int i = k; i <= n; i++) {
            for (int j = 0; j <= i - k; j++) {
                // 这两行就超时。。
                // double tmp = (sum[i] - sum[j]) / (i - j);
                // ret = max(ret, tmp);
                if (ret * (i - j) < sum[i] - sum[j]) {
                    ret = (sum[i] - sum[j]) / (i - j);
                }
            }
        }
        return ret;
    }
};

// 解法二：二分，待看
