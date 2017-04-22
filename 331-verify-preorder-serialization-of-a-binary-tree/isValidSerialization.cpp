#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>
#include <cstring>
#include <string.h>

using namespace std;
// 注意字符串的分割和比较
bool isValidSerialization(string preorder) {
    vector<string> preorderVec;

    int start = 0, len = 0;
    for (int i = 0; i < preorder.size(); i++) {
        if (preorder[i] == ',') {
            preorderVec.push_back(preorder.substr(start, len));
            len = 0;
            start = i + 1;
        }
        else {
            len++;
        }
    }
    preorderVec.push_back(preorder.substr(start, len));
    int diff = 1;
    // 判断是否小于0 就退出的情况，比如一堆#######,
    // 对于大于0的情况，即使一堆数字，但只要最后有#就可以，所以这个地方只用判断小于0
    // 如果不加这个，字符串全是####时间就比较长
    for (int i = 0; i < preorderVec.size(); i++) {
        if (--diff < 0) return false;
        if (preorderVec[i].compare("#") != 0) diff += 2;
    }

    return diff == 0;
}

int main () {
    cout << isValidSerialization("999,#,92,#,#") << endl;
    return 0;
}
