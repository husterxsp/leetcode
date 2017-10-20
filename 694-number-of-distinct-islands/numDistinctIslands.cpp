/**
https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
*/
class Solution {
public:
    vector<vector<int>> dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y, int m, int n) {
        if (grid[x][y] == 0) return {};

        vector<vector<int>> ret{{x, y}};
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n || vis[x1][y1] != 0) continue;
            vis[x1][y1] = 1;

            vector<vector<int>> tmp = dfs(grid, vis, x1, y1, m, n);
            if (!tmp.empty()) ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        return ret;
    }
    void translate(vector<vector<int>>& tmp) {
        vector<int> topLeft(2, INT_MAX);
        for (int i = 0; i < tmp.size(); i++) {
            topLeft[0] = min(topLeft[0], tmp[i][0]);
            topLeft[1] = min(topLeft[1], tmp[i][1]);
        }
        int offsetX = topLeft[0] - 0, offsetY = topLeft[1] - 0;
        for (int i = 0; i < tmp.size(); i++) {
            tmp[i][0] -= offsetX;
            tmp[i][1] -= offsetY;
        }
    }
    struct VectorHash {
        size_t operator()(const std::vector<vector<int>>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v[0]) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n));
        unordered_set<vector<vector<int>>, VectorHash> mySet;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] != 0 || grid[i][j] == 0) continue;

                vector<vector<int>> tmp = dfs(grid, vis, i, j, m, n);
                translate(tmp);
                mySet.insert(tmp);
            }
        }
        return mySet.size();
    }
private:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
