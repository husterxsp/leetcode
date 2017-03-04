#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
bool isIsomorphic(string s, string t) {
    unordered_map<char, char> myMap1;
    unordered_map<char, char> myMap2;
    if (s.length() != t.length()) return false;
    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];
        if (myMap1.count(c1)) {
            if (myMap1[c1] != c2) return false;
        }
        else {
            myMap1[c1] = c2;
        }

        if (myMap2.count(c2)) {
            if (myMap2[c2] != c1) return false;
        }
        else {
            myMap2[c2] = c1;
        }
    }
    return true;
}

int main () {
    cout << isIsomorphic("ab", "aa") << endl;
    return 0;
}
