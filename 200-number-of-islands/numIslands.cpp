#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<int>>& vis) {
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (x < 0 || x >= m || y < 0 || y >= n) continue;
        if (grid[x][y] == '1' && !vis[x][y]) bfs(x, y, m, n, grid, vis);
    }
}
int numIslands(vector<vector<char>>& grid) {
    if (!grid.size()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int ret = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && !vis[i][j]) {
                ret++;
                bfs(i, j, m, n, grid, vis);
            }
        }
    }
    return ret;
}

int main () {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << numIslands(grid) << endl;
    return 0;
}
