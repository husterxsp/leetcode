class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0, n = s.length();
        while (pos < n) {
            if (pos + k > n) reverse(s.begin() + pos, s.end());
            else reverse(s.begin() + pos, s.begin() + pos + k);
            pos += 2 * k;
        }
        return s;
    }
};
