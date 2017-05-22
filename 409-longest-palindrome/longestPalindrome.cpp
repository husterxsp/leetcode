#include <iostream>
#include <unordered_map>
using namespace std;

/**
 理解错了题意。。WA了两次。。
 */
int longestPalindrome(string s) {
    int ret = 0, mid = 0;
    unordered_map<char, int> myMap;
    for (char c : s) myMap[c]++;
    for (auto itor : myMap) {
        int num = itor.second;
        ret += num;
        if (num % 2 == 1) {
            ret--;
            mid = true;
        }
    }
    return mid ? ret + 1 : ret;
}

int main() {
    cout << longestPalindrome("aaa") << endl;
    return 0;
}
