class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // row 代表第一行
        // col 代表第一列
        vector<int> row(n), col(m);
        for (int i = 0; i < ops.size(); i++) {
            for (int j = 0; j < ops[i][0]; j++) col[j]++;
            for (int j = 0; j < ops[i][1]; j++) row[j]++;
        }
        int i = 1, j = 1;
        while (i < row.size()) {
            if (row[i] == row[0]) i++;
            else break;
        }
        while (j < col.size()) {
            if (col[j] == col[0]) j++;
            else break;
        }
        return i * j;
    }
};
