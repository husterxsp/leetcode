#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPartion(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (i + 1 > j - 1 || isPartion[i + 1][j - 1])) {
                isPartion[i][j] = true;
            }
        }
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (isPartion[j][i - 1]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n];
}

int main() {
    cout << minCut("aab") << endl;
    return 0;
}
