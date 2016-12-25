#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 26进制转换
string convertToTitle(int n) {
    string map = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret = "";
    while (n > 0) {
        int m = n % 26;
        if (m == 0) m = 26;
        ret = map[m] + ret;
        n = (n - m) / 26;
    }
    return ret;
}

int main() {
    cout << convertToTitle(27) << endl;
    return 0;
}
