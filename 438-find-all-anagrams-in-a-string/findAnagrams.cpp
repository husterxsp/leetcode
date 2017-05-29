#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    int sSize = s.size(), pSize = p.size();
    if (p == "") {
        for (int i = 0; i <= sSize; i++) ret.push_back(i);
        return ret;
    }
    if (pSize > sSize) return ret;
    unordered_set<char> mySet(p.begin(), p.end());
    sort(p.begin(), p.end());

    for (int i = 0; i <= sSize - pSize; i++) {
        char c = s[i];
        if (mySet.find(c) != mySet.end()) {
            string tmp(s.begin() + i, s.begin() + i + pSize);
            sort(tmp.begin(), tmp.end());
            if (tmp == p) {
                ret.push_back(i);
                // "xyzxyzxyz", "xyz"的重复计算
                while (s[i + pSize] == s[i]) {
                    i++;
                    ret.push_back(i);
                }
                // "aaacaaa", "aaa"中间遇到aac则及早break
                if (mySet.find(s[i + pSize]) == mySet.end()) {
                    i += pSize;
                }
            }
        }
    }
    return ret;
}

int main() {
    findAnagrams("xyzxyzxyz", "xyz");
    return 0;
}
