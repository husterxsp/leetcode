#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool canCross(vector<int>& stones) {
    if (stones[1] != 1) return false;
    int n = stones.size();
    vector<unordered_set<int>> dp(n);
    dp[1].insert(1);
    for (int i = 1; i < n; i++) {
        for (int k : dp[i]) {
            for (int j = i + 1; j < n; j++) {
                int units = stones[j] - stones[i];
                if (units > k + 1) break;
                else if (units >= k - 1) {
                    dp[j].insert(units);
                }
            }
        }
    }
    return !dp.back().empty();
}

int main() {
    vector<int> stones = {0,1,3,6,10,15,16,21};
    cout << canCross(stones) << endl;
    return 0;
}
