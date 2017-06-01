#include <iostream>
#include <vector>
#include <string>

using namespace std;
string addString(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    // long_max 长度19
    if (max(n1, n2) < 19) return to_string(stol(s1) + stol(s2));

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int pos = 0, sum = 0, carry = 0, remain = 0, num1, num2;
    string ret = "";
    while (pos < n1 || pos < n2) {
        num1 = pos >= n1 ? 0 : s1[pos] - '0';
        num2 = pos >= n2 ? 0 : s2[pos] - '0';

        sum = num1 + num2 + carry;
        carry = sum / 10;
        remain = sum % 10;
        ret = to_string(remain) + ret;
    }
    if (remain) ret = to_string(remain) + ret;
    return ret;
}
bool isAdditiveNumber(string num) {
    int n = num.size();

    // iLen表示第一个数的长度，jLen表示第二个数的长度
    for (int iLen = 1; iLen < (n + 1) / 2; iLen++) {
        if (num[0] == '0' && iLen > 1) break;
        for (int jLen = 1; (n - iLen - jLen) >= max(iLen, jLen); jLen++) {
            if (num[iLen] == '0' && jLen > 1) break;

            string s1 = num.substr(0, iLen), s2 = num.substr(iLen, jLen), s3 = "";
            int curPosition = iLen + jLen;
            while (1) {
                s3 = addString(s1, s2);
                if (num.substr(curPosition, s3.size()) != s3 || curPosition + s3.size() > n) break;
                if (curPosition + s3.size() == n) return true;

                s1 = s2;
                s2 = s3;
                curPosition += s2.size();
            }
        }
    }
    return false;
}

int main () {
    cout << isAdditiveNumber("0235813") << endl;
    return 0;
}
