#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <utility> // pair
#include <stdlib.h>
#include <unordered_set>

using namespace std;

// 思路：
// 1. runtime error: ['O'], 边界条件又未考虑。。
// 2. wrong answer:
// Input:   ["OOO","OOO","OOO"]
// Output:  ["OOO","OXO","OOO"]
// Expected:["OOO","OOO","OOO"]
// 3. wrong answer: (排查了下原因是那个方向循环，+改变方向执行BFS(), 后忘记-了)
//input:    ["OXOOOOOOO","OOOXOOOOX","OXOXOOOOX","OOOOXOOOO","XOOOOOOOX","XXOOXOXOX","OOOXOOOOO","OOOXOOOOO","OOOOOXXOO"]
//Output:   ["OXOOOOOOO","OOOXOOOOX","OXOXOOOOX","OOOOXOOOO","XXOOOOOOX","XXOOXOXOX","OOOXOOOOO","OOOXOOOOO","OOOOOXXOO"]
//Expected: ["OXOOOOOOO","OOOXOOOOX","OXOXOOOOX","OOOOXOOOO","XOOOOOOOX","XXOOXOXOX","OOOXOOOOO","OOOXOOOOO","OOOOOXXOO"]
// 4. 再次 Runtime Error： 大概是递归层次太深？栈溢出
// ["OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO"]
// void BFS(vector<vector<char>> &board, int i, int j, int m, int n) {
//     const int dir[4][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//     if (i < 0 || j < 0 || i >= m || j >= n) return;
//     if (board[i][j] == 'O') {
//         board[i][j] = 'I';
//         for (int d = 0; d < 4; d++) {
//             i += dir[d][0];
//             j += dir[d][1];
//             BFS(board, i, j, m, n);
//             i -= dir[d][0];
//             j -= dir[d][1];
//         }
//     }
//     else {
//         return;
//     }
// }
//
// void solve(vector<vector<char>>& board) {
//     int m = board.size();
//     if (m == 0) return;
//     int n = board[0].size();
//     int x = 0, y = 0;
//     while (y < n) {
//         if (board[x][y] == 'O') {
//             board[x][y] = 'I';
//             BFS(board, x + 1, y, m, n);
//         }
//         y++;
//     }
//     y--;
//     while (x < m) {
//         if (board[x][y] == 'O') {
//             board[x][y] = 'I';
//             BFS(board, x, y - 1, m, n);
//         }
//         x++;
//     }
//     x--;
//     while (y >= 0) {
//         if (board[x][y] == 'O') {
//             board[x][y] = 'I';
//             BFS(board, x - 1, y, m, n);
//         }
//         y--;
//     }
//     y++;
//     while (x >= 0) {
//         if (board[x][y] == 'O') {
//             board[x][y] = 'I';
//             BFS(board, x, y + 1, m, n);
//         }
//         x--;
//     }
//
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (board[i][j] == 'I') {
//                 board[i][j] = 'O';
//             }
//             else if (board[i][j] == 'O') {
//                 board[i][j] = 'X';
//             }
//         }
//     }
// }

void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    stack<pair<int, int>> s;

    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') {
            s.push(make_pair(i, 0));
        }
        if (board[i][n - 1] == 'O') {
            s.push(make_pair(i, n - 1));
        }
    }
    for (int i = 0; i < n; i++) {
        if (board[0][i] == 'O') {
            s.push(make_pair(0, i));
        }
        if (board[m - 1][i] == 'O') {
            s.push(make_pair(m - 1, i));
        }
    }
    while (!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        board[x][y] = 'I';
        if (x > 0 && board[x - 1][y] == 'O') s.push(make_pair(x - 1, y));
        if (x < m - 1 && board[x + 1][y] == 'O') s.push(make_pair(x + 1, y));
        if (y > 0 && board[x][y - 1] == 'O') s.push(make_pair(x, y - 1));
        if (y < n - 1 && board[x][y + 1] == 'O') s.push(make_pair(x, y + 1));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'I') {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'O','O','O','O','O','O','O','O','O','O','O','O','O'},
        {'X','X','X','X','X','X','X','X','X','X','X','X','O'},
        {'O','O','O','O','O','O','O','O','O','O','O','O','O'}
    };
    solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0;j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
