#include <iostream>
#include <vector>
/**
    搞不定。。这题考啥？..
*/
using namespace std;
int strongPasswordChecker(string s) {
    int ret = 0, n = s.size();
    if (n < 6) ret += 6 - n;
    if (n > 20) ret += n - 20;

    int lower = 1, upper = 1, digit = 1, repeatNum = 0;
    vector<string> repeatArr;
    string repeatStr = "";
    s += "$";
    for (int i = 0; i < n + 1; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') lower = 0;
        else if (c >= 'A' && c <= 'Z') upper = 0;
        else if (c >= '1' && c <= '9') digit = 0;

        if (i > 0 && c == s[i - 1]) {
            repeatStr += c;
        }
        else if (repeatStr.size() > 2) {
            repeatNum += repeatStr.size() / 3;
            repeatArr.push_back(repeatStr);
            repeatStr = c;
        }
        else {
            repeatStr = c;
        }
    }
    int sum = lower + upper + digit;
    if (n < 6) {
        // 需要增加
        ret = max(ret, max(sum, repeatNum));
    }
    else if (n > 20) {
        // 需要删除
        ret = ret / 2 + repeatNum;
        ret = max(ret, sum);
    }
    else {
        // 直接替换
        ret = max(sum, repeatNum);
    }

    return ret;
}
int main() {

    cout << strongPasswordChecker("AAAAAAaaaaaaAAAAAAaaaaaa") << endl;
}
