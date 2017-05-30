class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();

        int ret = 0;
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                for (int d = 0; d < 4; d++) {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    if (x < 0 || y < 0 || x >= m || y >= n) ret++;
                    else if (!grid[x][y]) ret++;
                }
            }
        }
        return ret;
    }
};
