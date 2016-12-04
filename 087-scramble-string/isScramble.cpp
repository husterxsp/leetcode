#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <algorithm>
using namespace std;

// wrong answer: abc, bca;
// 空字符串怎么算？
// 既然是动态规划
// 思路1：二维数组，每行每列有相等 ?
// 思路2：这个题是不是等价于求s1的排列组合里是不是有s2 ?
// 递归。。。AC
bool isScramble(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    if (l1 != l2) return false;
    if (l1 == 0) return true;
    vector<int> str(27, 0);

    for (int i = 0; i < l1; i++) {
        str[s1[i] - 'a']++;
        str[s2[i] - 'a']--;
    }
    for (int i = 0; i < 27; i++) {
        if (str[i] != 0) return false;
    }

    // 递归终止条件
    if (l1 == 1) return true;

    for (int i = 1; i < l1; i++) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i), s2.substr(i))) return true;
        if (isScramble(s1.substr(0, i), s2.substr(l1 - i)) &&
            isScramble(s1.substr(i), s2.substr(0, l1 - i))) return true;
    }
    return false;
}

int main() {
    cout << isScramble("abc", "bca");
    return 0;
}
