/**
    递归解，超时
*/
class Solution {
public:
    struct myHash {
        size_t operator()(pair<int, int> __val) const {
            return static_cast<size_t>(__val.first * 101 + __val.second);
        }
    };
    int bfs(vector<vector<int>>& forest, unordered_set<pair<int, int>, myHash> mySet,
            pair<int, int> target, vector<vector<int>> vis, int m, int n) {\

        if (mySet.find(target) != mySet.end()) return 0;
        if (mySet.empty()) return -1;

        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_set<pair<int, int>, myHash> tmp;

        for (auto s : mySet) {
            for (int i = 0; i < 4; i++) {
                int x = s.first + dir[i][0];
                int y = s.second + dir[i][1];

                if (x < 0 || x >= m || y < 0 || y >= n || forest[x][y] == 0 || vis[x][y]) continue;

                vis[x][y] = 1;
                tmp.insert({x, y});
            }
        }
        int ret = bfs(forest, tmp, target, vis, m, n);

        return ret == -1 ? ret : ret + 1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        map<int, pair<int, int>> myMap;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] < 1) continue;
                myMap[forest[i][j]] = {i, j};
            }
        }

        int ret = 0;
        pair<int, int> start{0, 0};

        for (auto it : myMap) {
            unordered_set<pair<int, int>, myHash> mySet{start};
            vector<vector<int>> vis(m, vector<int>(n));

            vis[start.first][start.second] = 1;

            int steps = bfs(forest, mySet, it.second, vis, m, n);
            if (steps == -1) return -1;

            ret += steps;
            start = it.second;
        }

        return ret;
    }
};

/**
    非递归解，AC
*/

class Solution {
public:
    int bfs(vector<vector<int>>& forest, pair<int, int> start, pair<int, int> target, int m, int n) {
        if (start == target) return 0;

        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> myQueue;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        vis[start.first][start.second] = 1;
        myQueue.push(start);

        int steps = 0;
        while (!myQueue.empty()) {
            int sz = myQueue.size();
            steps++;

            for (int i = 0; i < sz; i++) {
                int row = myQueue.front().first, col = myQueue.front().second;
                myQueue.pop();

                for (int i = 0; i < 4; i++) {
                    int x = row + dir[i][0];
                    int y = col + dir[i][1];

                    if (x < 0 || x >= m || y < 0 || y >= n || forest[x][y] == 0 || vis[x][y]) continue;

                    if (target.first == x && target.second == y) return steps;

                    vis[x][y] = 1;
                    myQueue.push({x, y});
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        map<int, pair<int, int>> myMap;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] < 1) continue;
                myMap[forest[i][j]] = {i, j};
            }
        }

        int ret = 0;
        pair<int, int> start{0, 0};

        for (auto it : myMap) {
            int steps = bfs(forest, start, it.second,  m, n);
            if (steps == -1) return -1;

            ret += steps;
            start = it.second;
        }

        return ret;
    }
};
