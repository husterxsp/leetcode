// 单源最短路径
// 此处用bellman-ford 更方便，从边着手考虑。
// 如果用dijkstra的话，还需要构造一个 邻接矩阵。
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distance(N + 1, 100000);
        distance[K] = 0;

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < times.size(); j++) {
                int u = times[j][0], v = times[j][1], w = times[j][2];

                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }
        int MAX = *max_element(distance.begin() + 1, distance.end());
        return MAX == 100000 ? -1 : MAX;
    }
};
