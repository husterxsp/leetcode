class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        if (!m) return vector<vector<int>>();
        int n = M[0].size();
        vector<vector<int>> ret(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, surround = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (i + k >= 0 && i + k < m && j + l >= 0 && j + l < n) {
                            surround++;
                            sum += M[i + k][j + l];
                        }
                    }
                }
                ret[i][j] = sum / surround;
            }
        }
        return ret;
    }
};
