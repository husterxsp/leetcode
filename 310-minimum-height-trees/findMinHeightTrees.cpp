#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/**
 TLE。。。。
 */
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> myGraph;
    for (auto pair : edges) {
        int first = pair.first, second = pair.second;
        myGraph[first].push_back(second);
        myGraph[second].push_back(first);
    }
    vector<int> ret, dp(n, 0);

    int minHeight = INT_MAX, curHeight = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<int> vis, v1 = {i};
        curHeight = 0;
        while (!v1.empty()) {
            unordered_set<int> tmp;
            for (auto node : v1) {
                if (dp[node] == 0 || dp[node] + curHeight <= minHeight) {
                    tmp.insert(myGraph[node].begin(), myGraph[node].end());
                }
            }
            for (auto visNode : vis) tmp.erase(visNode);

            vis = v1;
            v1 = tmp;

            curHeight++;
            if (curHeight > minHeight) break;
        }
        dp[i] = curHeight;
        if (curHeight < minHeight) {
            ret.clear();
            ret.push_back(i);
            minHeight = curHeight;
        }
        else if (curHeight == minHeight) {
            ret.push_back(i);
        }
    }
    return ret;
}

int main () {
    vector<pair<int, int>> edges{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    findMinHeightTrees(6, edges);
    return 0;
}
