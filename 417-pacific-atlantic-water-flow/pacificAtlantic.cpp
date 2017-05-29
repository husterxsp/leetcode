#include <iostream>
#include <vector>

using namespace std;
/**
 1. 第一次submit, W/A, 111/113, 对于相邻的相等的情况没考虑清楚，先处理不相等的，相等的之后处理
 2. 以后注意传的参数不能简单的写成i, j。调了好久就因为传参是i,j, for循环里也用了i,j.....
 */
vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void search(vector<vector<int>>& matrix, vector<vector<bool>>& vis, vector<vector<pair<int, int>>>& save,
            int i, int j, int m, int n) {

    if (vis[i][j]) return;

    vis[i][j] = true;
    vector<pair<int, int>> tmpDir;
    for (int d = 0; d < 4; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];
        if (x < 0 || y < 0) save[i][j].first = true;
        else if (x >= m || y >= n) save[i][j].second = true;
        else if (matrix[i][j] >= matrix[x][y]) {
            if (!vis[x][y]) {
                if (matrix[i][j] == matrix[x][y]) {
                    tmpDir.push_back({x, y});
                }
                else {
                    search(matrix, vis, save, x, y, m, n);
                }
            }

            save[i][j].first = save[i][j].first || save[x][y].first;
            save[i][j].second = save[i][j].second || save[x][y].second;
        }
    }
    for (int k = 0; k < tmpDir.size(); k++) {
        int x = tmpDir[k].first;
        int y = tmpDir[k].second;
        search(matrix, vis, save, x, y, m, n);

        save[i][j].first = save[i][j].first || save[x][y].first;
        save[i][j].second = save[i][j].second || save[x][y].second;
    }
}
vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> ret;
    int m = matrix.size();
    if (!m) return ret;
    int n = matrix[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<pair<int, int>>> save(m, vector<pair<int, int>>(n, {0,0}));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            search(matrix, vis, save, i, j, m, n);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (save[i][j].first && save[i][j].second) {
                ret.push_back({i, j});
            }
        }
    }
    return ret;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    pacificAtlantic(matrix);
    return 0;
}
