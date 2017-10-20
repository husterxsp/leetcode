class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y, int m, int n) {
        if (grid[x][y] == 0) return 0;

        int ret = 1;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n || vis[x1][y1] != 0) continue;
            vis[x1][y1] = 1;

            ret += dfs(grid, vis, x1, y1, m, n);
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n));

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, dfs(grid, vis, i, j, m, n));
            }
        }
        return ret;
    }
private:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
