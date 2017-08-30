class Solution {
public:
    void help(vector<vector<char>>& board, int x, int y, int m, int n, vector<vector<int>>& vis) {
        vis[x][y] = 1;
        // 遍历周围8个格子看有没有雷，有就置为雷的个数，没有就置为B并递归
        if (board[x][y] == 'M') return;
        if (board[x][y] == 'E') {
            int mines = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int x1 = x + i, y1 = y + j;
                    if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n || (x == x1 && y == y1)) continue;
                    if (board[x1][y1] == 'M') mines++;
                }
            }
            if (mines > 0) {
                board[x][y] = mines + '0';
                return;
            }

            board[x][y] = 'B';
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int x1 = x + i, y1 = y + j;
                    if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n || (x == x1 && y == y1) || vis[x1][y1]) continue;
                    help(board, x1, y1, m, n, vis);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty()) return board;

        int x = click[0], y = click[1], m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n));

        // 是雷直接返回
        if (board[x][y] == 'M') board[x][y] = 'X';
        else help(board, x, y, m, n, vis);

        return board;
    }
};
