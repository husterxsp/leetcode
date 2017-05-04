#include <iostream>
#include <vector>

using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();

    vector<int> pre(n, 0);
    vector<int> cur(n, 0);

    int ret = 0;

    for (int j = 0; j < n; j++) {
        pre[j] = matrix[0][j] - '0';
        ret = max(ret, pre[j]);
    }

    for (int i = 1; i < m; i++) {
        cur[0] = matrix[i][0] - '0';
        ret = max(ret, cur[0]);

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '1') {
                cur[j] = min(cur[j - 1], min(pre[j - 1], pre[j])) + 1;
                ret = max(ret, cur[j]);
            }
        }
        pre = cur;
        fill(cur.begin(), cur.end(), 0);
    }
    return ret * ret;
}

int main () {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << maximalSquare(matrix) << endl;
    return '0';
}
