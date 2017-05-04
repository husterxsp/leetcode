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
int lengthOfLongestSubstring(string s) {
    unordered_set<char> mySet;
    int ret = 0, left = 0, right = 0, n = s.size();

    while (left < n && right < n) {
        if (mySet.find(s[right]) == mySet.end()) {
            mySet.insert(s[right++]);
            ret = max(ret, right - left);
        }
        else {
            mySet.erase(s[left++]);
        }
    }
    return ret;
}
