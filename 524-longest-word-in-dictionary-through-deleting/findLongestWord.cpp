class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        map<char, vector<int>> sMap;
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]].push_back(i);
        }

        string ret;

        for (int i = 0; i < d.size(); i++) {
            string cur = d[i];

            
        }

        return ret;
    }
};
