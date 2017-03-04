#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j >= 0; j--) {
            if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1)) != wordDict.end()) {
                dp[i + 1] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

int main(){
    string s = "leetcode";
    vector<string> list = {"leet", "code"};
    cout << wordBreak(s, list) << endl;
    return 0;
}
