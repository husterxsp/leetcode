class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] >= s[i]) continue;

            char maxNum = s[i];
            int maxIndex = i;
            for (int j = i; j < s.size(); j++) {
                if (s[j] >= maxNum) {
                    maxNum = s[j];
                    maxIndex = j;
                }
            }

            int k;
            for (k = i - 1; k >= 0; k--) {
                if (maxNum <= s[k]) break;
            }

            char tmp = s[k + 1];
            s[k + 1] = s[maxIndex];
            s[maxIndex] = tmp;

            break;
        }
        return stoi(s);
    }
};
