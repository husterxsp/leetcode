#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct Node {
    vector<int> board;
    int x, y, hash;
    int moves;
    Node(vector<int> board, int x, int y, int hash, int moves)
        :board(board), x(x), y(y), hash(hash), moves(moves){}
    Node(){}
};

bitset<720> flags;
vector<vector<int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<int> factorial{1,1,2,6,24,120,720,5040,40320,362880};

int cantor(vector<int> board) {
    int x = 0, n = board.size();

    for (int i = 0; i < n; i++) {
        int smaller = 0;
        for (int j = i + 1; j < n; j++) {
            if (board[i] > board[j]) smaller++;
        }
        x += factorial[n - 1 - i] * smaller;
    }

    return x;
}

bool check(vector<int> board) {
    int reverseNum = 0;
    for (int i = 0; i < board.size(); i++) {
        if (board[i] == 0) continue;
        for (int j = i + 1; j < board.size(); j++) {
            if (board[j] == 0) continue;
            if (board[i] > board[j]) {
                reverseNum++;
            }
        }
    }
    return reverseNum % 2 == 0;
}

int slidingPuzzle(vector<vector<int>>& board) {
    vector<int> tmpboard;
    int ret = 0, x = 0, y = 0, target = cantor({1,2,3,4,5,0});

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                x = i;
                y = j;
            }
            tmpboard.push_back(board[i][j]);
        }
    }

    if (!check(tmpboard)) return -1;

    queue<Node> q;
    q.push(Node(tmpboard, x, y, cantor(tmpboard), 0));

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.hash == target) {
            return cur.moves;
        }
        for (int i = 0 ; i < 4; i++) {
            int tmpX = cur.x + dir[i][0];
            int tmpY = cur.y + dir[i][1];
            if (tmpX < 0 || tmpX > 1 || tmpY < 0 || tmpY > 2) continue;

            Node tmp = cur;
            tmp.board[cur.x * 3 + cur.y] = tmp.board[tmpX * 3 + tmpY];
            tmp.board[tmpX * 3 + tmpY] = 0;

            tmp.x = tmpX;
            tmp.y = tmpY;
            tmp.hash = cantor(tmp.board);
            tmp.moves++;

            if (flags[tmp.hash]) continue;
            flags.set(tmp.hash);

            q.push(tmp);
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> board{
        {3,2,4},
        {1,5,0}
    };
    cout << slidingPuzzle(board) << endl;

    return 0;
}
