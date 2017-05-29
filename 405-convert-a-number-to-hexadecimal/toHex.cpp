#include <iostream>
#include <vector>

/**
    1. 注意需要转换为unsigned再计算
    2. 负数的补码是将对应绝对值按位取反, 加1
*/

using namespace std;
string toHex(int num) {
    vector<string> hexMap = {"a", "b", "c", "d", "e", "f"};
    if (num == 0) return "0";
    unsigned int tmpNum = num;
    if (num < 0) {
        tmpNum = ~abs(num) + 1;
    }
    string ret = "";
    while (tmpNum) {
        int remain = tmpNum % 16;
        if (remain >= 10) {
            ret = hexMap[remain - 10] + ret;
        }
        else {
            ret = to_string(remain) + ret;
        }
        tmpNum /= 16;
    }
    return ret;
}
int main() {
    cout << toHex(26) << endl;
    return 0;
}
