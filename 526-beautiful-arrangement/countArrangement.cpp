class Solution {
public:
    void search(int& ret, vector<int> vis, int pos, int N) {
        if (pos > N) {
            ret++;
            return;
        }
        for (int i = 1; i < N; i++) {
            if (vis[i] == 0 && (i % pos == 0 || pos % i == 0)) {
                vis[i] = 1;
                search(ret, vis, pos + 1, N);
                vis[i] = 0;
            }
        }
    }
    int countArrangement(int N) {
        int ret = 0;
        vector<int> vis(N + 1, 0);
        search(ret, vis, 1, N);
        return ret;
    }
};
