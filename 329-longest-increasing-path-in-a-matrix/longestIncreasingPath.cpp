#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int search(vector<vector<int>>& matrix, vector<vector<int>>& vis, int x, int y, int m, int n) {
    int ret = 1;
    vis[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int row = x + dir[d][0];
        int col = y + dir[d][1];
        if (row < 0 || col < 0 || row >= m || col >= n || matrix[row][col] <= matrix[x][y]) continue;

        if (vis[row][col] != 0) {
            ret = max(ret, vis[row][col] + 1);
        }
        else {
            ret = max(ret, search(matrix, vis, row, col, m, n) + 1);
        }
    }
    vis[x][y] = ret;
    return ret;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = (int)matrix.size();
    if (m == 0) return 0;
    int n = (int)matrix[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    int ret = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, search(matrix, vis, i, j, m, n));
        }
    }
    return ret;
}

int main () {
    vector<vector<int>> matrix = {
        {9,9,4},
        {10,6,8},
        {2,1,1}
    };
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}
