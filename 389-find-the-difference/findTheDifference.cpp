#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
        解法1，map
    */
    char findTheDifference(string s, string t) {
        unordered_map<char, int> myMap;
        for (auto c : s) myMap[c]--;
        for (auto c : t) {
            myMap[c]++;
            if (myMap[c] == 1) return c;
        }
        return 'a';
    }
    /**
        解法2，位运算
        char 如果不初始化的话值应该是null,Ascii是0？怎么不太对
    */
    char findTheDifference(string s, string t) {
        char ret = 0;
        for (auto c : s) ret ^= c;
        for (auto c : t) ret ^= c;
        return ret;
    }

};

int main() {
    Solution s =  Solution();
    cout << s.findTheDifference("abcd", "abcde") << endl;
    return 0;
}
