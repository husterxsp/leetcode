一下递归解 1790 ms。。。
参看discuss 分情况讨论的非递归解。

class Solution {
public:
    bool end(vector<string> board) {
        for (int i = 0; i <= 2; i++) {
            char c = board[i][0];
            if (board[i][1] == board[i][2] && board[i][2] == c && c != ' ') return true;

            c = board[0][i];
            if (board[1][i] == board[2][i] && board[2][i] == c && c != ' ') return true;
        }
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
            return true;
        return false;
    }
    bool dfs(vector<string> target, vector<string> board, char c) {
        // for (int i = 0; i <= 2; i++) {
        //     for (int j = 0; j <= 2; j++) {
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }
        if (target == board) return true;
        if (end(board)) return false;

        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = c;
                    if (dfs(target, board, c == 'X' ? 'O' : 'X')) return true;
                    board[i][j] = ' ';
                }
            }
        }
        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int xNum = 0, oNum = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <=2; j++) {
                if (board[i][j] == 'X') xNum++;
                else if (board[i][j] == 'O') oNum++;
            }
        }
        if (!(xNum == oNum || xNum == oNum + 1)) return false;
        return dfs(board, vector<string>(3, "   "), 'X');
    }
};
