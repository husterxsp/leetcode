/**
    题目：时间t从0开始增加，从（0，0）开始移动，可以移动的条件是 当前点和将要移动到的点的elevation都 >=t
*/

/**
    直接DFS 超时
    加上二分

    一点小问题：为啥这里的DFS的vis置1 后不需要置0 ?不用回溯？
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int height, int x, int y, int n) {
    if (x == n - 1 && y == n - 1) return true;

    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tmpX = x + dir[i][0];
        int tmpY = y + dir[i][1];

        if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n || grid[tmpX][tmpY] > height || vis[tmpX][tmpY] == 1) continue;
        if (dfs(grid, vis, height, tmpX, tmpY, n)) return true;
    }
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int low = 0, high = n * n;

    while (low < high) {
        vector<vector<int>> vis(n, vector<int>(n));
        int mid = low + (high - low) / 2;

        if (grid[0][0] <= mid && dfs(grid, vis, mid, 0, 0, n)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
//    vector<vector<int>> grid{{26,99,80,1,89,86,54,90,47,87},{9,59,61,49,14,55,77,3,83,79},{42,22,15,5,95,38,74,12,92,71},{58,40,64,62,24,85,30,6,96,52},{10,70,57,19,44,27,98,16,25,65},{13,0,76,32,29,45,28,69,53,41},{18,8,21,67,46,36,56,50,51,72},{39,78,48,63,68,91,34,4,11,31},{97,23,60,17,66,37,43,33,84,35},{75,88,82,20,7,73,2,94,93,81}};
//
    vector<vector<int>> grid{{3,2},{0,1}};

    cout << swimInWater(grid) << endl;

    return 0;
}
