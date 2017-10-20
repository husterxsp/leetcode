/**
    递归解，超时
    最后概率的计算是直接除以pow(8, K)
    因为每一步走出的概率都是1/8

*/
class Solution {
public:
    double dfs(int N, int k, int r, int c, vector<vector<vector<double>>>& dp) {
        if (r < 0 || r > N - 1 || c < 0 || c > N - 1) return 0.0;
        if (k == 0) return 1.0;
        if (dp[r][c][k] != -1.0) return dp[r][c][k];

        double ret = 0;
        for (auto d : dir) {
            double tmp = dfs(N, k - 1, r + d[0], c + d[1], dp);
            if (tmp > 0) ret += tmp;
        }
        return dp[r][c][k] = ret;
    }
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0) return 1;
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K + 1, -1.0)));

        dfs(N, K, r, c, dp);

        return dp[r][c][K] / pow(8, K);
    }
private:
    vector<vector<int>> dir{
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {-2, -1}, {-1, -2}, {1,-2}, {2, -1}
    };
};
