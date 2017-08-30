class Solution {
public:
    string predictPartyVictory(string senate) {
        unordered_map<char, int> all, lose;
        for (char c : senate) all[c]++;

        while (1) {
            string tmp = "";
            for (auto c : senate) {
                if (c == 'R') {
                    if (lose['R']) {
                        lose['R']--;
                        all['R']--;
                    }
                    else {
                        if (all['D'] == 0) return "Radiant";
                        else lose['D']++;

                        tmp += 'R';
                    }
                }
                else {
                    if (lose['D']) {
                        lose['D']--;
                        all['D']--;
                    }
                    else {
                        if (all['R'] == 0) return "Dire";
                        else lose['R']++;

                        tmp += 'D';
                    }
                }
            }
            senate = tmp;
        }
    }
};
