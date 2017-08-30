// int splitArray(vector<int>& nums, int m) {
//     if (m == 1) return accumulate(nums.begin(), nums.end(), 0);
//
//     int ret = INT_MAX;
//     int n = nums.size();
//     for (int i = 0; i + m <= n; i++) {
//         vector<int> newNums(nums.begin() + i + 1, nums.end());
//
//         int sum = accumulate(nums.begin(), nums.begin() + i + 1, 0);
//
//         ret = min(ret, max(sum, splitArray(newNums, m - 1)));
//     }
//     return ret;
// }

class Solution {
public:
    int help(vector<int>& nums, int m, int n, int start, vector<int> sum) {
        int ret = INT_MAX, tmp1, tmp2;
        if (m == 0) return 0;
        if (m == 1) {

            int tmp3 = start == 0 ? sum[n - 1] : (sum[n - 1] - sum[start - 1]);

            return tmp3;
        }

        for (int i = start; i <= n - start - m; i++) {

            if (start == 0) {
                tmp1 = sum[i];
            }
            else {
                tmp1 = sum[i] - sum[start - 1];
            }

            int tmp2 = help(nums, m - 1, n, i + 1, sum);

            ret = min(ret, max(tmp1, tmp2));
        }
        return ret;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sum(n);

        sum[0] = nums[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];

        return help(nums, m, n, 0, sum);
    }
};
