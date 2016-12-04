#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <algorithm>
using namespace std;
//          s
// t  x x x x x x x x
// 思路：二维数组，相等的时候取左、上和，不相等时取左
// wrong answer: "ccc", "c", expected: 3, output: 1
// wrong answer: "ddd", "dd", expected: 3, output: 6
// int numDistinct(string s, string t) {
//     int tLen = t.size(), sLen = s.size();
//     vector<vector<int>> arr(2, vector<int>(sLen + 1, 0));
//
//     for (int i = 1; i <= tLen; i++) {
//         for (int j = i; j <= sLen; j++) {
//             if (i > j) {
//                 arr[1][j] = 0;
//             }
//             else if (t[i - 1] == s[j - 1]) {
//                 if (i == 1) {
//                     arr[1][j] = arr[1][j - 1] + 1;
//                 }
//                 else {
//                     arr[1][j] = max(arr[0][j] + arr[1][j - 1], 1);
//                 }
//             }
//             else {
//                 arr[1][j] = arr[1][j - 1];
//             }
//         }
//         for (int k = 1; k <= sLen; k++) {
//             arr[0][k] = arr[1][k];
//             arr[1][k] = 0;
//         }
//     }
//     return arr[0][sLen];
// }

// http://bangbingsyb.blogspot.com/2014/11/leetcode-distinct-subsequences.html
// 思路：二维数组，相等的时候取左、上左和，不相等时取左。。。上面自己想的递推公式写错了啊啊啊，
// 那这种递推公式一般怎么写，只能看，找规律么？
// 另外就是，这个链接里用的是一维滚动数组，我想的还是二维的数组，虽然只有两行。。。
int numDistinct(string s, string t) {
    int tLen = t.size(), sLen = s.size();
    vector<int> arr(sLen + 1, 1);
    for (int i = 1; i <= tLen; i++) {
        int upLeft = arr[0];
        arr[0] = 0;
        for (int j = 1; j <= sLen; j++) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            if (t[i - 1] == s[j - 1]) arr[j] += upLeft;
            upLeft = temp;
        }
    }
    return arr[sLen];
}

int main() {
    cout << numDistinct("rabbit", "rabit");
    return 0;
}
