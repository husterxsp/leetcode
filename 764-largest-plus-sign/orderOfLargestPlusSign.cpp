// 直接求解。。没啥特别的。。
#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <queue>

using namespace std;
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
//    if (mines.empty()) return N;
    vector<int> row(N, N), col(N, N);

    vector<vector<int>> grid(N, vector<int>(N, 1));
    for (int i = 0; i < mines.size(); i++) {
        int x = mines[i][0], y = mines[i][1];
        grid[x][y] = 0;
        row[x]--;
        col[y]--;
    }

    vector<vector<int>> rowSum(N, vector<int>(N)), colSum(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rowSum[i][j] = rowSum[i][j - 1] + grid[i][j];
            colSum[i][j] = colSum[i][j - 1] + grid[j][i];
        }
    }

    int largestK = (N + 1) / 2;

    while (largestK > 0) {
        for (int i = largestK - 1; i <= N - largestK; i++) {
            if (row[i] < 2 * largestK - 1) continue;
            for (int j = largestK - 1; j <= N - largestK; j++) {
                if (col[j] < 2 * largestK - 1) continue;

                if (rowSum[i][j + largestK - 1] - rowSum[i][j - largestK + 1] + grid[i][j - largestK + 1] == 2 * largestK - 1 &&
                    colSum[j][i + largestK - 1] - colSum[j][i - largestK + 1] + grid[i - largestK + 1][j] == 2 * largestK - 1
                    ) {
                    return largestK;
                }
            }
        }
        largestK--;
    }

    return largestK;
}
int main() {

    vector<vector<int>> mines = {
        {0,0}
    };
    cout << orderOfLargestPlusSign(1, mines) << endl;

    return 0;
}
