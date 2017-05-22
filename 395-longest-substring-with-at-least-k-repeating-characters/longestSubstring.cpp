#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstring(string s, int k) {
    if (k <= 1) return s.size();
    unordered_map<char, int> myMap;
    for (char c : s) myMap[c]++;

    s += '0';
    int n = s.size(), start = 0, end = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        if (myMap[s[i]] >= k) {
            end++;
        }
        else {
            ret = max(ret, end - start);
            start = end = i;
        }
    }
    return ret;
}
int main() {
    cout << longestSubstring("ababacb", 3) << endl;
    return 0;
}
