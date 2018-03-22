参考discuss,直接求 曼哈顿距离。用bfs 搞了好久

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for (int i = 0; i < ghosts.size(); i++) {
            if (abs(target[0]) + abs(target[1]) >= abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]))
                return false;
        }
        return true;
    }
};
