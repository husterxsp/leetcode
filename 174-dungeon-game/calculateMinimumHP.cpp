#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
/**
 http://renfengliu.github.io/2016/03/23/Dynamic-Programming/
 最先初始化的是公主所在的房间的起始生命值，然后慢慢向第一个房间扩散，
 不断的得到各个位置的最优的起始生命值。递归方程:
 dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
 */
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    if (!m) return 1;
    int n = dungeon[0].size();
    vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    hp[m][n - 1] = hp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int need = min(hp[i][j + 1], hp[i + 1][j]) - dungeon[i][j];
            // 注意题中说明初始值是正值，所以此处至少为1
            hp[i][j] = max(1, need);
        }
    }
    return hp[0][0];
}

int main () {
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
