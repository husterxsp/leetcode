#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

// 暴力解->查找时间太长->无序map，缩小查找时间
using namespace std;
bool isPalindrome(string str, int left, int right){
    while(left < right) {
        if(str[left++] != str[right--]) return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ret;
    unordered_map<string, int> myMap;
    set<int> mySet;

    for (int i = 0; i < words.size(); i++) {
        mySet.insert(words[i].size());
        myMap[words[i]] = i;
    }

    for (int i = 0; i < words.size(); i++) {
        string rev = words[i];
        reverse(rev.begin(), rev.end());

        if (myMap.count(rev) && myMap[rev] != i) {
            ret.push_back({i, myMap[rev]});
        }

        int len = rev.size();
        auto fin = mySet.find(len);

        for (auto iter = mySet.begin(); iter != fin; iter++) {
            // 此处注意应当从有回文片段的字符串想起。
            int d = *iter;
            // abcdd、cba
            // ddcba、cba
            if (isPalindrome(rev, 0, len - d - 1) && myMap.count(rev.substr(len - d))) {
                ret.push_back({i, myMap[rev.substr(len - d)]});
            }
            // ddabc、cba
            // cbadd、cba
            if (isPalindrome(rev, d, len - 1) && myMap.count(rev.substr(0, d))) {
                ret.push_back({myMap[rev.substr(0, d)], i});
            }
        }
    }
    return ret;
}

int main () {
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    palindromePairs(words);
    return 0;
}
