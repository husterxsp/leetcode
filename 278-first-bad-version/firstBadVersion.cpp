#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
bool isBadVersion(int version) {
    if (version >= 3) return true;
    return false;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int mid = 0;
    while (left < right) {
        // 1. 注意取平均值溢出
        // 2. 两种取平均的方式四舍五入不同, 取上还是取下
        // 3. 返回值的处理
        // mid = (left + right) / 2;  取下

        // 还有...  int mid = left + (right - left) / 2; 取下

//         mid = right - (right - left) / 2; // 取上

        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}

int main () {
    cout << firstBadVersion(7) << endl;
    return 0;
}
