#include <iostream>
#include <string>
#include <map>

using namespace std;
bool repeatedSubstringPattern(string s) {
    int n = s.size();
    // i 表示重复次数
    for (int i = 2; i <= n; i++) {
        if (n % i != 0) continue;
        int len = n / i;
        string str = s.substr(0, len);

        int j = 1;
        while (j < i) {
            if (s.substr(len * j, len) != str) break;
            j++;
        }
        if (j == i) return true;
    }
    return false;
}

int main() {
    cout << repeatedSubstringPattern("aaaaa") << endl;
    return 0;
}
