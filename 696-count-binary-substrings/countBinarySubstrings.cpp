class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0, ret = 0, len1 = 0, len2 = 0, n = s.size();
        char cur = s[0];

        while (i < n && s[i] == cur) {
            len1++;
            i++;
        }
        while (i < n) {
            cur = s[i];
            while (s[i] == cur) {
                len2++;
                i++;
            }
            ret += min(len1, len2);
            len1 = len2;
            len2 = 0;
        }
        return ret;
    }
};
