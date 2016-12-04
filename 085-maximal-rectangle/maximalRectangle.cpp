#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <algorithm>
using namespace std;

// struct Point {
//     int x, y, area;
//     Point(int a, int b, int c)
//     : x(a), y(b), area(c){}
// };

// 思路：想按照动态规划的思路解。。二维数组。。按行，按列，但是越想越复杂。。
// 主要是没法解决 1 0 1 1 这种中间有0的情况
//              1 1 1 1
// int maximalRectangle(vector<vector<char>>& matrix) {
//     int m = matrix.size(), n = matrix[0].size();
//     vector<vector<Point>> arr(m + 5, vector<Point>(n + 5, *(new Point(0, 0, 0)) ));
//
//     int maxX = 0, maxY = 0;
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (matrix[i][j] == 1) {
//                 arr[i][j].x = arr[i][j - 1].x + 1;
//                 arr[i][j].y = arr[i - 1][j].y + 1;
//
//                 arr[i][j].area = max(min(arr[i][j].x, arr[i - 1][j]) + arr[i - 1][j].area,
//                                      min(arr[i][j].x, arr[i][j - 1]) + arr[i][j - 1].area);
//             }
//         }
//     }
//
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//
//     return 0;
// }

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> stack(n + 1, 0);
    vector<int> width(n + 1, 0);

    if (n == 0) return 0;
    int top = 0, area = 0, newHeight;
    for (int i = 0; i <= n; i++) {
        // i 超出数组范围会导致heights[i]溢出
        newHeight = i < n ? heights[i] : -1;
        if (newHeight > stack[top]) {
            stack[++top] = newHeight;
            width[top] = 1;
        }
        else {
            int minH = 0, wid = 0;
            while (top >= 0 && stack[top] > newHeight) {
                wid += width[top];
                area = max(area, stack[top] * wid);
                top--;
            }
            stack[++top] = newHeight;
            width[top] = wid + 1;
        }
    }
    return area;
}
// 主要思路，参考第84题
// 思路1: 对二维数组的每一行运行84T中的函数，时间复杂度O(n^2)
// 思路2: 在网上搜了一下好像都是思路一这种O(n^2)的解。。。
// run time error: [] 什么鬼？？
// 另外：在计算二维数组的时候记得判断一下，m == 0
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = (m == 0 ? 0 : matrix[0].size());
    vector<vector<int>> height(m, vector<int>(n, 0));

    if (m == 0 || n == 0) return 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0') {
                height[i][j] = 0;
            }
            else {
                height[i][j] = (i == 0 ? 1 : height[i - 1][j] + 1);
            }
        }
    }
    int area = 0;
    for (int i = 0; i < m; i++) {
        area = max(area, largestRectangleArea(height[i]));
    }
    return area;
}

int main() {
    vector<vector<char>> a = {{}};
    cout << maximalRectangle(a);
    return 0;
}
