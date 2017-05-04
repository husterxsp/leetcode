#include <iostream>
#include <vector>

using namespace std;
/**
 区分首尾行和其他行
 http://www.cnblogs.com/springfor/p/3889414.html

 numRows = 3
 1   5   9
 2 4 6 8
 3   7
 */

string convert(string s, int numRows) {
    string ret = "";
    int n = s.size();

    if (numRows <= 1) return s;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < n; j += 2 * (numRows - 1)) {
            ret += s[j];
            // 其他行
            if (i != 0 && i != numRows - 1) {
                int tmp = j + 2 * (numRows - 1) - 2 * i;
                if (tmp < n) {
                    ret += s[tmp];
                }
            }
        }
    }
    return ret;
}

int main() {
    cout << convert("123456789", 3) << endl;
    return 0;
}
