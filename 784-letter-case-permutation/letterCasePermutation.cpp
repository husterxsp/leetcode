/**
    DFS & BFS

    DFS : 树
    BFS : 分层
*/
class Solution {
public:
    void help(string s, int pos, vector<string>& ret) {
        if (pos == s.size()) {
            ret.push_back(s);
            return;
        }

        help(s, pos + 1, ret);

        char c = s[pos];
        if (isalpha(c)) {
            s[pos] = islower(c) ? toupper(c) : tolower(c);
            help(s, pos + 1, ret);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        help(S, 0, ret);
        return ret;
    }
};
