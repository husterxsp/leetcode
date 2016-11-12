#include <iostream>
#include <vector>
using namespace std;

// AC
bool bfs(vector<vector<char>>& board, string word, vector<vector<int>> vis, int len, int i, int j){
    if(len == word.length()) return true;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    for(int d=0;d<4;d++){
        int x = i+dir[d][0];
        int y = j+dir[d][1];
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()) continue;
        if(!vis[x][y] && board[x][y] == word[len]){
            vis[x][y] = 1;
            if(bfs(board, word, vis, len+1, x, y)){
                return true;
            }
            vis[x][y] = 0;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    int len = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == word[len]){
                vis[i][j] = 1;
                if(bfs(board, word, vis, 1, i, j)){
                    return true;
                }
                vis[i][j] = 0;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> a = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << exist(a, "");
    return 0;
}
