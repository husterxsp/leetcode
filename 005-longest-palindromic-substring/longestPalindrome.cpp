#include <iostream>
#include <vector>

using namespace std;

string search(int left, int right, string s) {
    while (left >= 0 && right <= s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    int len = right - left - 1;
    return s.substr(left + 1, len);
}
string longestPalindrome(string s) {
    string ret = "";
    int left = 0, right = 0, n = s.size(), len;
    for (int i = 0; i < n; i++) {
        string odd = search(i, i, s);
        string even = search(i, i + 1, s);

        if (odd.size() > ret.size()) ret = odd;
        if (even.size() > ret.size()) ret = even;
    }
    return ret;
}

int main() {
    cout << longestPalindrome("babab") << endl;
    return 0;
}
