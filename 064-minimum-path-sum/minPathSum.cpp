#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> arr(m, vector<int>(n, 0));
    int i, j;

    arr[m-1][n-1] = grid[m-1][n-1];
    for(i=m-2;i>=0;i--){
        arr[i][n-1] = grid[i][n-1]+arr[i+1][n-1];
    }
    for(j=n-2;j>=0;j--){
        arr[m-1][j] = grid[m-1][j]+arr[m-1][j+1];
    }
    for(i=m-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            arr[i][j] = grid[i][j]+min(arr[i+1][j],arr[i][j+1]);
        }
    }
    return arr[0][0];
}

int main(){
    vector<vector<int>> a = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(a);
    return 0;
}