#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<int> dp(n, 1);
    int ret = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main() {
    vector<pair<int, int>> envelopes = {
        {5,4},
        {6,4},
        {6,7},
        {2,3}
    };
    cout << maxEnvelopes(envelopes) << endl;
    return 0;
}
