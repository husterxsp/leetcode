class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<vector<int>> range;

        for (int i = 0; i < words.size(); i++) {
            int len = words[i].size();
            int pos = S.find(words[i], 0);
            while (pos != string::npos) {
                range.push_back(vector<int>{pos, pos + len});
                pos = S.find(words[i], pos + 1);
            }
        }
        sort(range.begin(), range.end());

        for (int i = 1; i < range.size(); i++) {
            if (range[i][0] <= range[i - 1][1]) {

                range[i][0] = min(range[i][0], range[i - 1][0]);
                range[i][1] = max(range[i][1], range[i - 1][1]);

                range.erase(range.begin() + i - 1);

                i--;
            }
        }

        if (range.empty()) return S;

        string ret = S.substr(0, range[0][0]);

        for (int i = 0; i < range.size(); i++) {
            ret += "<b>" + S.substr(range[i][0], range[i][1] - range[i][0]) + "</b>";

            if (i < range.size() - 1) {
                ret += S.substr(range[i][1], range[i + 1][0] - range[i][1]);
            }

        }
        ret += S.substr(range.back()[1]);

        return ret;
    }
};
