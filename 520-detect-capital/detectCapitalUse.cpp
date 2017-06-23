class Solution {
public:
    bool detectCapitalUse(string word) {
        int upNum = 0, lowNum = 0, upPos = 0, lowPos = 0, n = word.length();

        for (int i = 0; i < n; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                upNum++;
                if (upPos == 0) upPos = i;
            }
            else if (word[i] >= 'a' && word[i] <= 'z') {
                lowNum++;
                if (lowPos == 0) lowPos = i;
            }
            else return false;
        }
        if (upNum == n || lowNum == n) return true;
        if (upPos == 0 && upNum == 1) return true;
        return false;
    }
};
