class Solution {
public:
    int help(vector<int>& nums, int target, unordered_map<int, int> &dp, int n) {
        if (dp.find(target) != dp.end()) return dp[target];

        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > target) break;
            if (nums[i] == target) {
                cur++;
                break;
            }
            else {
                cur += help(nums, target - nums[i], dp, n);
            }
        }
        return dp[target] = cur;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;

        dp[0] = 1;

        sort(nums.begin(), nums.end());

        return help(nums, target, dp, n);
    }
};
