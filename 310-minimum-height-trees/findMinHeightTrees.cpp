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
    vector<int> ret;
    unordered_set<int> vis, v1, v2;
    int minHeight = INT_MAX, curHeight = 0;
    for (int i = 0; i < n; i++) {
        v1 = {i};
        v2 = {};
        vis = {};
        curHeight = 0;
        while (!v1.empty() || !v2.empty()) {
            if (!v1.empty()) {
                for (auto node1 : v1) {
                    v2.insert(myGraph[node1].begin(), myGraph[node1].end());
                }
                for (auto visNode : vis) v2.erase(visNode);

                vis = v1;
                v1.clear();
            }
            else {
                for (auto node1 : v2) {
                    v1.insert(myGraph[node1].begin(), myGraph[node1].end());
                }
                for (auto visNode : vis) v1.erase(visNode);

                vis = v2;
                v2.clear();
            }
            curHeight++;
            if (curHeight > minHeight) break;
        }
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
    vector<pair<int, int>> edges{};
    findMinHeightTrees(1212, edges);
    return 0;
}
