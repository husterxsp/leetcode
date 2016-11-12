#include <iostream>
#include <vector>
#include <Map>
using namespace std;
//一开始打算按照四个方位分别写。。。写完发现都一样。。AC.
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> ret(n, vector<int>(n,0));
    int i, j;
// 上，右，下，左
//    for(i=0;i<n/2;i++){
//        for(j=i;i<n-j;j++){
//            ret[j][n-i-1] = matrix[i][j];
//        }
//    }
//
//    for(j=n/2;j<n/2;j++){
//        for(i=n-j;i<j;i++){
//            ret[j][n-i-1] = matrix[i][j];
//        }
//    }
//
//    for(i=n/2;i<n/2;i++){
//        for(j=n-i;j<i;j++){
//            ret[j][n-i-1] = matrix[i][j];
//        }
//    }
//
//    for(j=0;j<n/2;j++){
//        for(i=j;i<n-j;i++){
//            ret[j][n-i-1] = matrix[i][j];
//        }largestRectangleArea
//    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ret[j][n-i-1] = matrix[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrix[i][j] = ret[i][j];
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(matrix);
    return 0;
}
