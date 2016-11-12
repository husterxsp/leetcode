#include <iostream>
#include <vector>
using namespace std;

// 首先想到的是O(m*n)的空间; 其实还有O(m+n),即两个数组分别记录行列; 
// 其实还有O(1),也就是题干要求的do it in place。
void setRow(vector<vector<int>>& matrix, int x, int setRow){
    int m = matrix.size(), n = matrix[0].size();
    if(setRow){
        for(int i=0;i<n;i++){
            matrix[x][i] = 0;
        }
    } else {
        for(int i=0;i<m;i++){
            matrix[i][x] = 0;
        }
    }
}
void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()){
        return;
    }
    int m = matrix.size(), n=matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;
    for(int i=0;i<m;i++){
        if(!matrix[i][0]){
            firstColZero = true;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(!matrix[0][j]){
            firstRowZero = true;
            break;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(!matrix[i][j]){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<m;i++){
        if(!matrix[i][0]){
            setRow(matrix, i, 1);
        }
    }
    for(int i=1;i<n;i++){
        if(!matrix[0][i]){
            setRow(matrix, i, 0);
        }
    }
    
    if(firstColZero){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
    if(firstRowZero){
        for(int i=0;i<n;i++){
            matrix[0][i]=0;
        }
    }

}

int main(){
    vector<vector<int>> a = {
        {0,1}
    };
    setZeroes(a);
    return 0;
}