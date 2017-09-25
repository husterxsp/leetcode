/**
    参考discuss
*/
class Solution {
public:
    int root(unordered_map<int, int> &parent, int k) {
        if (parent[k] == 0) return k;

        parent[k] = root(parent, parent[k]);
        return parent[k];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> parent;
        for (auto edge : edges) {
            int pa = root(parent, edge[0]), pb = root(parent, edge[1]);
            if (pa == pb) return edge; //already connected
            parent[pb] = pa;
        }
        return vector<int>(2,3);
    }
};
