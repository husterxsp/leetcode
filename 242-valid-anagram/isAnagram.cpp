#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;

// 解法1 排序
// bool isAnagram(string s, string t) {
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     return s.compare(t) == 0;
// }

// 解法2 计数
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    vector<int> character(26, 0);
    for (int i = 0; i < n; i++) {
        character[s[i] - 'a']++;
        character[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (character[i] != 0) return false;
    }
    return true;
}

int main () {

    cout << isAnagram("hello", "helol") << endl;
    return 0;
}
