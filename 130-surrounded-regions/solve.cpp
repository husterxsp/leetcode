#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

const int dir[4][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool check(int i, int j, int m, int n){
    if(i==0 || i== n-1)return false;

    return true;
}
void BFS(vector<vector<char>> board, vector<vector<int>> vis, int i, int j){
    vis[i][j] = 1;
    for(int d=0;d<4;d++){
        i += dir[d][0];
        j += dir[d][1];
        
        BFS(board, vis, i, j);
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            if(board[i][j] == 'X') continue;
            BFS(board, vis, i, j);
        }
    }
}

int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'},
    }
    solve(board);
    return 0;
}
