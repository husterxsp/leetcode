// easy
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> hash;
        for (char c : licensePlate) if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') hash[tolower(c)]++;

        string ret;
        for (string str : words) {
            unordered_map<char, int> cur, tmpHash = hash;
            for (char c : str) if (c >= 'a' && c <= 'z') cur[c]++;

            if (cur.size() < tmpHash.size()) continue;
            for (auto it = tmpHash.begin(); it != tmpHash.end();) {
                if (it->second > cur[it->first]) break;
                tmpHash.erase(it++);
            }

            if (tmpHash.empty() && (ret == "" || str.size() < ret.size()))
                ret = str;
        }
        return ret;
    }
};
