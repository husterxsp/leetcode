#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
/*
    解法学习：http://www.cnblogs.com/grandyang/p/4523624.html
*/
bool isPalindrome(string s) {
    int len = (int)s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}
string shortestPalindrome(string s) {
    int len = (int)s.length();
    if (!len) return s;
    string ret = s;
    for (int i = len; i > 0; i--) {
        if (isPalindrome(s.substr(0, i))) {
            string prefix = s.substr(i, len - i);
            reverse(prefix.begin(), prefix.end());
            ret = prefix + ret;
            break;
        }
    }
    return ret;
}

// string shortestPalindrome(string s) {
//     string r = s;
//     reverse(r.begin(), r.end());
//     string t = s + "#" + r;
//     vector<int> next(t.size(), 0);
//     for (int i = 1; i < t.size(); ++i) {
//         int j = next[i - 1];
//         while (j > 0 && t[i] != t[j]) j = next[j - 1];
//         next[i] = (j += t[i] == t[j]);
//     }
//     return r.substr(0, s.size() - next.back()) + s;
// }
int main () {
    cout << shortestPalindrome("") << endl;
    return 0;
}
