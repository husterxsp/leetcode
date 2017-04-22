#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;

// 超时
// bool search(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<int>>& matrix, int target) {
//     if (i >= m || j >= n || matrix[i][j] > target) return false;
//     if (matrix[i][j] == target) return true;
//
//     if (vis[i][j]) return false;
//     vis[i][j] = true;
//
//     return search(i + 1, j, m, n, vis, matrix, target) || search(i, j + 1, m, n, vis, matrix, target);
// }
//
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();
//     if (m <= 0) return false;
//     int n = matrix[0].size();
//
//     vector<vector<bool>> vis(m, vector<bool>(n, false));
//     return search(0, 0, m, n, vis, matrix, target);
// }

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m <= 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        }
        else if (matrix[i][j] > target) {
            j--;
        }
        else {
            i++;
        }
        cout << matrix[i][j] << endl;
    }
    return false;
}

int main () {
    vector<vector<int>> matrix = {
        {5,9,11,12,14,17,20,22},
        {6,13,17,22,25,27,27,32},
        {9,15,22,26,28,31,35,39},
        {13,16,24,30,30,33,35,44},
        {16,19,28,34,39,44,47,47},
        {18,20,30,39,43,48,49,53},
        {22,25,32,40,48,52,56,59},
        {25,26,35,44,52,57,58,63},
        {25,31,36,47,52,60,60,63},
        {25,36,37,52,52,62,63,68}
    };
    cout << searchMatrix(matrix, 68) << endl;
    return 0;
}
