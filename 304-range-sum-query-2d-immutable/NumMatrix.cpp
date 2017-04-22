#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>> matrix) {
        dp = matrix;
        int m = matrix.size();
        if (!m) return;
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int i = row1; i <= row2; i++) {
            ret += dp[i][col2];
            if (col1 != 0) ret -= dp[i][col1 - 1];
        }
        return ret;
    }
};

int main () {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix obj = *new NumMatrix(matrix);
    cout << obj.sumRegion(1,2,2,4) << endl;
    return 0;
}
