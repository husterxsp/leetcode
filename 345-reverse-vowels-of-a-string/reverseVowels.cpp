#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;
bool isVowel(char c) {
    string vowel = "aeiouAEIOU";
    for (int i = 0; i < vowel.size(); i++) {
        if (c == vowel[i]) return true;
    }
    return false;
}
string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isVowel(s[left])) {
            left++;
        }
        while (left < right && !isVowel(s[right])) {
            right--;
        }
        swap(s[left++], s[right--]);
    }
    return s;
}

/**
    参考解：
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
    一些方法如find_first_of， swap都不熟悉
*/

int main() {
    cout << reverseVowels("leetcode") << endl;
    return 0;
}
