// 后续考虑优化，集合求交集，set
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<string> name(n);
        vector<set<string>> email(n);
        for (int i = 0; i < n; i++) {
            name[i] = accounts[i][0];
            email[i] = set<string>(accounts[i].begin() + 1, accounts[i].end());
        }

        while (1) {
            bool changed = false;
            for (int i = 1; i < name.size(); i++) {
                bool find = false;
                for (string s : email[i]) {
                    for (int j = 0; j < i; j++) {
                        if (email[j].find(s) != email[j].end()) {
                            email[j].insert(email[i].begin(), email[i].end());
                            email.erase(email.begin() + i);
                            name.erase(name.begin() + i);

                            find = true;
                            changed = true;
                            break;
                        }
                    }
                    if (find) break;
                }
                if (find) i--;
            }
            if (!changed) break;
        }

        vector<vector<string>> ret;
        for (int i = 0; i < name.size(); i++) {
            vector<string> tmp;

            tmp.insert(tmp.end(), name[i]);
            tmp.insert(tmp.end(), email[i].begin(), email[i].end());

            ret.push_back(tmp);
        }
        return ret;
    }
};
