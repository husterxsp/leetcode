class Solution {
public:
    string reverseWords(string s) {
        // 注意边界条件！空值，"",0,NULL等
        if (s.empty()) return "";
        istringstream myStr(s);
        string ret, str;
        while(myStr >> str) {
            reverse(str.begin(), str.end());
            ret += " " + str;
        }
        return ret.substr(1);
    }
};
