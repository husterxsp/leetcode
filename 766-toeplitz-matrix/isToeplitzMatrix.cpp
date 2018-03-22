class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        map<int, int> myMap;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            myMap[-i] = matrix[i][0];
        }
        for (int i = 0; i < n; i++) {
            myMap[i] = matrix[0][i];
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (myMap[j - i] != matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
