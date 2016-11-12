bool checkValid(char cur, bool used[9]){
    if(cur == '.') return true;
    if(used[cur - '1']) return false;
    return used[cur - '1'] = true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    bool used[9];
    for(int i=0; i<9; i++){
        fill(used, used + 9, false);
        for(int j=0; j<9; j++){
            if(!checkValid(board[i][j], used)){
                return false;
            }
        }
        fill(used, used + 9, false);
        for(int j=0; j<9; j++){
            if(!checkValid(board[j][i], used)){
                return false;
            }
        }
    }
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            fill(used, used + 9, false);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(!checkValid(board[row*3+i][col*3+j], used)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
