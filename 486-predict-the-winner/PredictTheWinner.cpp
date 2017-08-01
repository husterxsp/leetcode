/**
    暴力解法，能A但是效率低
*/
class Solution {
public:
    long search(vector<int> nums) {
        if (nums.empty()) return 0;
        if (nums.size() <= 2) return (long)max(nums.front(), nums.back());

        // 这里假设play2总能取最大值，所以play1取min
        long score1 = nums.front() + min(search(vector<int>(nums.begin() + 1, nums.end() - 1)),
                                         search(vector<int>(nums.begin() + 2, nums.end())));

        long score2 = nums.back() + min(search(vector<int>(nums.begin() + 1, nums.end() - 1)),
                                         search(vector<int>(nums.begin(), nums.end() - 2)));
        return max(score1, score2);
    }

    bool PredictTheWinner(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0);
        long score = search(nums);

        if (score >= sum / 2) return true;
        return false;
    }
};

/**
    动态规划，参看：https://leetcode.com/problems/predict-the-winner/#/solution

    动态规划的一种情况：二维，分别是数组的一个区间的起止

*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int a = nums[i] - dp[i + 1][j];
                int b = nums[j] - dp[i][j - 1];
                dp[i][j] = max(a, b);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
//--------。。。
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = n; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int a = nums[i] - dp[j];
                int b = nums[j] - dp[j - 1];
                dp[j] = max(a, b);
            }
        }
        return dp[n - 1] >= 0;
    }
};
