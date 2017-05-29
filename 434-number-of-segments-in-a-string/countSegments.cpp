class Solution {
public:
    int countSegments(string s) {
        s += " ";
        int ret = 0, n = s.size(), curLen = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                curLen++;
            }
            else if (curLen > 0) {
                ret++;
                curLen = 0;
            }
        }
        return ret;
    }
};
