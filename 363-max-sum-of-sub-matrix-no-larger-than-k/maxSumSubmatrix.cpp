/**
    解法1：暴力解
    sum[i][j] 表示点(i, j)和(0, 0) 形成的矩形的面积和
    以下求解中表示点(i1, j1)和(i, j)形成的矩形和
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

        int ret = INT_MIN;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
                for (int i1 = 1; i1 <= i; i1++) {
                    for (int j1 = 1; j1 <= j; j1++) {
                        int SUM = sum[i][j] - sum[i1 - 1][j] - sum[i][j1 - 1] + sum[i1 - 1][j1 - 1];
                        if (SUM <= k) ret = max(ret, SUM);
                    }
                }
            }
        }
        return ret;
    }
};

/*
    时间复杂度优化
*/
