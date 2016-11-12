#include <iostream>
#include <vector>
using namespace std;

// 解法1，递归层次太深，超时。改用解法2, AC
//int getUnique(int x, int y, int m, int n){
//    if(x==m || y==n){
//        return 1;
//    }
//    return getUnique(x+1, y, m, n) + getUnique(x, y+1, m, n);
//}
//
//int uniquePaths(int m, int n) {
//    if(m == 1 || n == 1){
//        return 1;
//    }
//    return getUnique(1, 1, m, n);
//}

int uniquePaths(int m, int n) {
    vector<vector<int>> arr(m, vector<int>(n, 0));
    int i, j;
    for(i=m-1;i>=0;i--){
        arr[i][n-1] = 1;
    }
    for(j=n-1;j>=0;j--){
        arr[m-1][j] = 1;
    }
    for(i=m-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            arr[i][j] = arr[i+1][j]+arr[i][j+1];
        }
    }
    return arr[0][0];
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
    return 0;
}