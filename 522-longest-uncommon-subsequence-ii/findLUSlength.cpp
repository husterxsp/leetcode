class Solution {
public:
    // check if a is a subsequence of b
    bool checkSub(string a, string b) {
        int i = 0;
        for (char c : b) {
            if (c == a[i]) i++;
            if (i == a.size()) break;
        }
        return i == a.size();
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size(), ret = -1, j;
        for (int i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                else if (checkSub(strs[i], strs[j])) break;
            }
            if (j == n) ret = max(ret, (int)strs[i].size());
        }
        return ret;
    }
};
