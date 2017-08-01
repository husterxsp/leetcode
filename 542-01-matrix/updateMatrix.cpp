/**
    BFS，queue
    另外注意以下的解法直接在matrix上修改，节省空间
    待再看
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> myQueue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) myQueue.push({i, j});
                else matrix[i][j] = INT_MAX;
            }
        }
        while (!myQueue.empty()) {
            auto p = myQueue.front();
            myQueue.pop();
            for (auto d : dirs) {
                int x = p.first + d[0], y = p.second + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[p.first][p.second]) {
                    matrix[x][y] = matrix[p.first][p.second] + 1;
                    myQueue.push({x, y});
                }
            }
        }
        return matrix;
    }
};
