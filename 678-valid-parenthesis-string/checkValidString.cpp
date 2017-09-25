class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if (!n) return true;

        string ret = "";
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (s[i] == '(' || s[i] == '*') ret += c;
            else {
                int starPos = -1, find = 0;
                for (int j = ret.size() - 1; j >= 0; j--) {
                    if (starPos == -1 && ret[j] == '*') starPos = j;
                    if (ret[j] == '(') {
                        ret.erase(j, 1);
                        find = 1;
                        break;
                    }
                }
                if (!find) {
                    if (starPos != -1) ret.erase(starPos, 1);
                    else return false;
                }
            }
        }

        vector<int> starVec, leftVec;
        for (int i = 0; i < ret.size(); i++) {
            if (ret[i] == '(') leftVec.push_back(i);
            else starVec.push_back(i);
        }

        if (starVec.size() < leftVec.size()) return false;
        int i = leftVec.size() - 1, j = starVec.size() - 1;

        while (i >= 0 && j >= 0) {
            if (leftVec[i] < starVec[j]) {
                i--;
                j--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
