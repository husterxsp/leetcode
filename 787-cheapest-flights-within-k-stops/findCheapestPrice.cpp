单源最短路径

1: bellman-ford

#include <iostream>
#include <vector>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    // 边长最多K+1,所以松弛K+1次
    for (int i = 1; i <= K + 1; i++) {

        // 分层
        vector<int> tmp(distance);

        for (auto f : flights) {
            tmp[f[1]] = min(tmp[f[1]], distance[f[0]] + f[2]);
        }
        distance = tmp;
    }

    return distance[dst] == 1e9 ? -1 : distance[dst];
}

int main() {
    vector<vector<int>> flights{{0,1,100},{1,2,100},{0,2,500}};

    findCheapestPrice(3, flights, 0, 2, 1);
    findCheapestPrice(3, flights, 0, 2, 0);
}


2. BFS

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> distance(n, 1e9);
        distance[src] = 0;

        queue<int> q;
        q.push(src);
        while (K >= 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();

                for (auto f : flights) {
                    if (f[0] == cur && distance[f[0]] + f[2] < distance[f[1]]) {
                        distance[f[1]] = distance[f[0]] + f[2];
                        q.push(f[1]);
                    }
                }
            }
            K--;
        }
        return distance[dst] == 1e9 ? -1 : distance[dst];
    }
};

3. DP：参考discuss

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // K 原本表示stop, 即停顿，K++后表示边
        K++;

        vector<vector<int>> dp(n, vector<int>(K + 1, 1e9));

        dp[src][0] = 0;

        // 最多K条边
        for (int i = 1; i <= K; i++) {

            for (int j = 0; j < n; j++) {
                dp[j][i] = dp[j][i - 1];
            }

            for (auto f : flights) {
                dp[f[1]][i] = min(dp[f[1]][i], dp[f[0]][i - 1] + f[2]);
            }
        }
        return dp[dst][K] == 1e9 ? -1 : dp[dst][K];
    }
};


4. Dijkstra
