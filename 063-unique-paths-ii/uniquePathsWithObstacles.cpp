#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> arr(m, vector<int>(n, 0));
    int i, j;
    for(i=m-1;i>=0;i--){
        if(obstacleGrid[i][n-1]){
            break;
        }
        arr[i][n-1] = 1;
    }
    for(j=n-1;j>=0;j--){
        if(obstacleGrid[m-1][j]){
            break;
        }
        arr[m-1][j] = 1;
    }
    for(i=m-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            if(obstacleGrid[i][j]){
                arr[i][j] = 0;
            } else {
                arr[i][j] = arr[i+1][j]+arr[i][j+1];
            }
        }
    }
    return arr[0][0];
}

int main(){
    vector<vector<int>> a = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(a);
    return 0;
}