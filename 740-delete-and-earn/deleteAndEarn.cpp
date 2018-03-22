// 递归解法
class Solution {
public:
    int help(vector<vector<int>> sum, int start, int n, vector<int>& dp) {
        if (start >= n) return 0;
        if (start == n - 1) return dp[start] = sum[start][1];

        if (dp[start] >= 0) return dp[start];

        if (sum[start][0] < sum[start + 1][0] - 1) return dp[start] = sum[start][1] + help(sum, start + 1, n, dp);

        return dp[start] = max(sum[start][1] + help(sum, start + 2, n, dp), help(sum, start + 1, n, dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) myMap[nums[i]] += nums[i];

        vector<vector<int>> sum;
        for (auto it : myMap) {
            sum.push_back({it.first, it.second});
        }

        int n = sum.size();

        vector<int> dp(n + 1, -1);
        return help(sum, 0, n, dp);
    }
};

// 非递归解
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) myMap[nums[i]] += nums[i];

        vector<vector<int>> sum;
        for (auto it : myMap) sum.push_back({it.first, it.second});

        int n = sum.size(), take = sum[0][1], skip = 0;
        for (int i = 1; i < n; i++) {
            int tmpSkip = max(take, skip);
            int tmpTake = sum[i][1];

            if (sum[i][0] - 1 > sum[i - 1][0]) tmpTake += max(take, skip);
            else tmpTake += skip;

            take = tmpTake;
            skip = tmpSkip;
        }
        return max(take, skip);
    }
};
