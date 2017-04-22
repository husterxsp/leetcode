#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
string minWindow(string s, string t) {
    int left = 0, right = 0, type = 0;
    string ret = "";
    unordered_map<char, int> myMap;

    for (int i = 0; i < t.length(); i++) {
        if (myMap.count(t[i])) {
            myMap[t[i]]++;
        }
        else {
            type++;
            myMap[t[i]] = 1;
        }
    }
    for (; right < s.length(); right++) {
        char c = s[right];
        if (myMap.count(c)) {
            myMap[c]--;
            if (myMap[c] == 0) {
                type--;
            }
            if (type > 0) continue;
        }
        else {
            continue;
        }
        for (; left < right; left++) {
            c = s[left];
            if (!myMap.count(c)) continue;
            if (myMap[c] < 0) {
                myMap[c]++;
                continue;
            }
            break;
        }
        string tmp = s.substr(left, right - left + 1);
        ret = ret == "" || tmp.length() < ret.length() ? tmp : ret;
    }
    return ret;
}

int main(){
    cout << minWindow("ABBBA", "AA") << endl;
    return 0;
}
