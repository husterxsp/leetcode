/*
    参考：http://www.cnblogs.com/grandyang/p/6254527.html
*/
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        unordered_set<string> mySet{words.begin(), words.end()};
        for (string word : words) {
            int n = word.size();
            if (n == 0) continue;

            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && mySet.find(word.substr(i, j - i)) != mySet.end()) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    ret.push_back(word);
                    break;
                }
            }
        }
        return ret;
    }
};
