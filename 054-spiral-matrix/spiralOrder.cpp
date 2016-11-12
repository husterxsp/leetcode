#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int dir[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ret;
    int m, n, i, j;
    
    // 注意判断空值时候的问题，若m=0,则没有matrix[0],所以m,n分开写
    m = matrix.size();
    if(m == 0){
        return ret;
    }
    n = matrix[0].size();
    if(n == 0){
        return ret;
    }
    
    vector<vector<int>> vis;
    
    for(i=0;i<m;i++){
        vector<int> tmp;
        for(j=0;j<n;j++){
            tmp.push_back(0);
        }
        vis.push_back(tmp);
    }
    
    int r, c, k;
    r = c = k = 0;
    while (k < m*n) {
        for(int d=0;d<4;){
            while (r>=0 && r < m && c >= 0 && c < n && !vis[r][c]) {
                ret.push_back(matrix[r][c]);
                vis[r][c] = 1;
                k++;
                r += dir[d][0];
                c += dir[d][1];
            }
            r -= dir[d][0];
            c -= dir[d][1];
            d++;
            if(d <= 3){
                r += dir[d][0];
                c += dir[d][1];
            } else {
                r += dir[0][0];
                c += dir[0][1];
            }
 
        }
    }
    return ret;
}

int main(){
    vector<vector<int>> in = {
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9, 10, 11, 12}
    };
    
    cout << spiralOrder(in).size();
    return 0;
}
