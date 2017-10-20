/**
    思路：先找出有两个父节点的node（根据题意顶多有一个?），然后将这两个边candA,candB记录（注意A,B先后顺序
    是按照在edges出现的顺序）。
    然后找环，如果有环，而且也有candA，那么这个candA应该在这个环里，直接返回candA
    如果没有candA，直接返回导致环的边
    最后如果没有环，则返回candB（因为candB相对candB靠后）

    参考：https://discuss.leetcode.com/topic/105108/c-java-really-working-solution-union-find-with-explanation
*/
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0];
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        }
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k)
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};
