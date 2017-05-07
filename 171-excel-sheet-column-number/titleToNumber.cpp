#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
    26进制
*/
int titleToNumber(string s) {
    int ret = 0;
    for (auto c : s) {
        int tmp = c - 'A' + 1;
        ret = ret * 26 + tmp;
    }
    return ret;
}

int main () {
    cout << titleToNumber("AB") << endl;
    return 0;
}
