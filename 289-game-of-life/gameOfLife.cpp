#include <iostream>
#include <vector>

using namespace std;
/**
解法1，新建了数组保存状态，但是不太满足题目in-place的要求
*/
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();

    vector<vector<int>> next(m, vector<int>(n, 0));

    vector<vector<int>> dir = {
        {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {1, 0},
        {-1, 1}, {-1, -1}, {-1, 0},
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;
            for (int d = 0; d < 8; d++) {
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) live++;
            }
            next[i][j] = live;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = next[i][j];
            if (live < 2 || (live > 3 && bo ard[i][j] == 1)) {
                board[i][j] = 0;
            }
            else if (live == 3 && board[i][j] == 0) {
                board[i][j] = 1;
            }
        }
    }
}

/**
解法2，用四个状态表示四个转换方式
0：死->死
1：活->活
2：活->死
3：死->活
*/
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();

    vector<vector<int>> dir = {
        {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {1, 0},
        {-1, 1}, {-1, -1}, {-1, 0},
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;
            for (int d = 0; d < 8; d++) {
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) live++;
            }
            if (board[i][j] && (live < 2 || live > 3)) {
                board[i][j] = 2;
            }
            else if (!board[i][j] && live == 3) {
                board[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2) {
                board[i][j] = 0;
            }
            if (board[i][j] == 3) {
                board[i][j] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>> board = {
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 0}
    };
    gameOfLife(board);
    return 0;
}
