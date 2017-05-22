#include <iostream>
#include <unordered_map>
using namespace std;

/**
这题一开始都没看懂题意。。。
*/
int firstUniqChar(string s) {
    int n = s.size();
    unordered_map<char, int> myMap;

    for (auto c : s) myMap[c]++;
    for (int i = 0; i < n; i++) {
        if (myMap[s[i]] == 1) return i;
    }
    return -1;
}
int main() {
    cout << firstUniqChar("loveleetcode") << endl;
    return 0;
}
