/**
    思路：BFS，但是从内层到外层的遍历总是超时，太多重复计算？。。。
    参考网上的解法，从外层到内层遍历。。。
*/

// 超时解
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> myGraph;
        for (auto pair : edges) {
            int first = pair.first, second = pair.second;
            myGraph[first].push_back(second);
            myGraph[second].push_back(first);
        }
        vector<int> ret, dp(n);

        int minHeight = INT_MAX, curHeight = 0;
        for (int i = 0; i < n; i++) {
            vector<int> vis(n);
            queue<int> nodeQue;

            curHeight = 0;
            nodeQue.push(i);
            while (!nodeQue.empty()) {
                int sz = nodeQue.size();

                for (int i = 0; i < sz; i++) {
                    int node = nodeQue.front();
                    nodeQue.pop();

                    for (auto n : myGraph[node]) {
                        if (vis[node] || dp[n] + curHeight > minHeight) continue;
                        nodeQue.push(n);
                    }
                    vis[node] = 1;
                }

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
};

// 改进，参考：https://discuss.leetcode.com/topic/30572/share-some-thoughts/2
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        vector<set<int>> adj(n);

        for (auto edge : edges) {
            int first = edge.first, second = edge.second;
            adj[first].insert(second);
            adj[second].insert(first);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }

        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i : leaves) {
                int j = *adj[i].begin();
                adj[j].erase(i);
                if (adj[j].size() == 1) newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
