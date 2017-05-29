#include <iostream>
#include <vector>

using namespace std;
int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    if (!m) return 0;
    int n = board[0].size();

    int ret = 0;
    bool hadX = false;
    for (int i = 0; i < m; i++) {
        // 注意此处换行的时候也要讲hadX置为false啊啊啊。
        hadX = false;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                hadX = false;
            }
            else if (!hadX && (i == 0 || board[i - 1][j] == '.')) {
                hadX = true;
                ret++;
            }
        }
    }

    return ret;
}
int main() {
    vector<vector<char>> board = {
        {'.', 'X'},
        {'X', '.'},
    };
    cout << countBattleships(board) << endl;
    return 0;
}
