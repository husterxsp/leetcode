/*
    参考：http://www.cnblogs.com/grandyang/p/5928987.html
*/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size(), ret = 0, mx = INT_MIN;

        /*
            template<
                class T,
                class Container = std::vector<T>,
                class Compare = std::less<typename Container::value_type>
            > class priority_queue;
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<int>> vis(m, vector<int>(n));
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!(i == 0 || i == m - 1 || j == 0 || j == n - 1)) continue;
                q.push({heightMap[i][j], i * n + j});
                vis[i][j] = 1;
            }
        }

        while (!q.empty()) {
            auto val = q.top(); q.pop();
            int height = val.first, x = val.second / n, y = val.second % n;

            mx = max(mx, height);

            for (auto d : dir) {
                int x1 = x + d[0], y1 = y + d[1];
                if (x1 >= m || x1 < 0 || y1 >= n || y1 < 0 || vis[x1][y1]) continue;

                vis[x1][y1] = 1;
                ret += max(mx - heightMap[x1][y1], 0);
                q.push({heightMap[x1][y1], x1 * n + y1});
            }
        }
        return ret;
    }
};
