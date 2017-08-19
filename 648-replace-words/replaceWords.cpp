/*
    比较简单
*/
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> sen;
        stringstream ist(sentence);
        string word;
        while (ist >> word) sen.push_back(word);

        for (int i = 0; i < sen.size(); i++) {
            for (int j = 0; j < dict.size(); j++) {
                if (sen[i].compare(0, dict[j].size(), dict[j]) == 0) {
                    sen[i] = dict[j];
                    break;
                }
            }
        }
        string ret;
        for (int i = 0; i < sen.size(); i++) ret += " " + sen[i];

        return ret.size() ? ret.substr(1) : "";
    }
};
