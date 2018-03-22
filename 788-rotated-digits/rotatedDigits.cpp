class Solution {
public:
    int rotatedDigits(int N) {
        int ret = 0, fail = 0, success = 0;
        for (int i = 0; i <= N; i++) {
            string s = to_string(i);
            fail = 0, success = 0;

            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '3' || s[j] == '4' || s[j] == '7') {
                    fail = 1;
                    break;
                }
                if (s[j] == '2' || s[j] == '5' || s[j] == '6' || s[j] == '9') {
                    success = 1;
                }
            }
            if (fail) continue;
            if (success) ret++;
        }
        return ret;
    }
};
