/**
    题目本身是二维区域，再考虑到对于每个点的对应步数不同，值也不同，所以需要再加一维
    三维dp
    以下解法需要注意for循环的顺序。。比如k应该放在最外层？
*/
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(N + 1, 0)));
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int k = 1; k <= N; k++) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    for (int d = 0; d < 4; d++) {
                        int x1 = x + dir[d][0], y1 = y + dir[d][1];

                        if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) dp[x][y][k] += 1;
                        else dp[x][y][k] += dp[x1][y1][k - 1];
                    }
                    dp[x][y][k] %= 1000000007;
                }
            }
        }
        return dp[i][j][N];
    }
};
