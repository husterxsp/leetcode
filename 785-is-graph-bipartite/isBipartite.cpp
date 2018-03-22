/**
    染色法，注意可能是非连通图
*/

深搜

class Solution {
public:
    bool dfs(int node, int color, vector<int>& colorArr, vector<vector<int>>& graph) {
        colorArr[node] = color;
        for (int i = 0; i < graph[node].size(); i++) {
            // 一样的颜色，失败
            if (colorArr[graph[node][i]] == color) return false;
            // 递归
            if (colorArr[graph[node][i]] == 0 && !dfs(graph[node][i], -color, colorArr, graph)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorArr(n);

        // 循环以免非连通
        for (int i = 0; i < n; i++) {
            if (colorArr[i] == 0 && !dfs(i, 1, colorArr, graph)) return false;
        }
        return true;
    }
};

---------广搜---------

class Solution {
public:
    bool bfs(int node, vector<int>& colorArr, vector<vector<int>>& graph) {
        colorArr[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < graph[node].size(); i++) {
                int child = graph[node][i];

                if (colorArr[child] == 0) {
                    q.push(child);
                    colorArr[child] = -colorArr[node];
                }
                // 一样的颜色，失败
                if (colorArr[child] == colorArr[node]) return false;

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorArr(n);

        // 循环以免非连通
        for (int i = 0; i < n; i++) {
            if (colorArr[i] == 0 && !bfs(i, colorArr, graph)) return false;
        }
        return true;
    }
};
