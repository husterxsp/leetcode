class Solution {
public:
    // ...注意迟到是连续的三次...
    bool checkRecord(string s) {
        return (s.find('A') == string::npos || s.find('A') == s.rfind('A')) && s.find("LLL") == string::npos;
    }
};
