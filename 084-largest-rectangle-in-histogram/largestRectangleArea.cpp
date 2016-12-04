#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <algorithm>
using namespace std;

// 参考网上的解答
// http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
//
// 一些需要注意的：
// 1. for 循环n + 1, 最后一个0,避免递增的数组最后计算结果为0
// 2. 这个算法其实计算了所有可能的长方形的面积了。
// http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html 对这个算法的解释是不对的
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

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << largestRectangleArea(a);
    return 0;
}
