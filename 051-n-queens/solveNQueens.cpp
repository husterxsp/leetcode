#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> res;
int queen[1000] = {0};

bool isValid(int k){
    int i;
    for(i=1;i<k;i++){
        if(queen[i] == queen[k] || abs(queen[i]-queen[k]) == abs(i-k)){
            return false;
        }
    }
    return true;
}

void generateQueens(int k, int n){
    // 结束
    if(k == n+1){
        vector<string> tmp;
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++){
                if(j == queen[i]){
                    str += "Q";
                } else {
                    str += ".";
                }
            }
            tmp.push_back(str);
        }
        res.push_back(tmp);
        for(int i=1;i<=n;i++){
            cout << queen[i] << " ";
        }
        cout << endl;
        return;
    }
    // 第k个皇后，第i列
    for(int i=1;i<=n;i++){
        queen[k] = i;
        if(!isValid(k)){
            continue;
        }
        generateQueens(k+1, n);
    }
}

vector<vector<string>> solveNQueens(int n) {
    generateQueens(1, n);
    return res;
}

int main(){
    int n;
    cin >> n;
    solveNQueens(n);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
