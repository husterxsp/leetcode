#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left=0, right=m*n-1, mid=0, r, c;
    while (left<=right) {
        mid=(left+right)/2;
        r = mid/n;
        c = mid%n;
        if(matrix[r][c] == target) return true;
        if(matrix[r][c] > target){
            right = mid-1;
        }else {
            left = mid+1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> a = {
        {1}
    };
    cout << searchMatrix(a, 1);
    return 0;
}