/*
    参考：http://www.cnblogs.com/grandyang/p/6850657.html
    数组&子数组问题->DP
    限定区间范围->二维DP
*/
class Solution {
public:
    int help(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
        if (j < i) return 0;
        if (dp[i][j][k]) return dp[i][j][k];
        int ret = (k + 1) * (k + 1) + help(boxes, i + 1, j, 0, dp);

        for (int m = i + 1; m <= j; m++) {
            if (boxes[m] == boxes[i]) {
                ret = max(ret, help(boxes, i + 1, m - 1, 0, dp) + help(boxes, m, j, k + 1, dp));
            }
        }
        return dp[i][j][k] = ret;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0};

        return help(boxes, 0, n - 1, 0, dp);
    }
};
