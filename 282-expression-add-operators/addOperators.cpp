/**
    hard...
*/
class Solution {
public:
    void help(string num, int target, string cur, vector<string>& ret) {
        if (stoi(num) == target) {
            cur += "+" + num;
            ret.push_back(cur);
            return;
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string>& ret;

    }
};
