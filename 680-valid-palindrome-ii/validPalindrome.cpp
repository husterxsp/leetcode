class Solution {
public:
    bool help(string s, int del) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            }
            else if (del == 1) return false;
            else {
                return help(s.substr(start, end - start), 1) ||
                help(s.substr(start + 1, end - start), 1);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return help(s, 0);
    }
};
