#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (!row) return {};
    int col = matrix[0].size();

    int n = row * col, cur = 0;

    vector<int> ret(n, 0);
    int flag = 1, i = 0, j = 0;
    for (int k = 0; k < row + col - 1; k++) {
        while (1) {
            ret[cur++] = matrix[i][j];
            i -= flag;
            j += flag;
            if (i < 0 || i >= row || j < 0 || j >= col) {
                if (i >= row) {
                    i--;
                    j += 2;
                }
                else if (j >= col) {
                    j--;
                    i += 2;
                }
                else if (i < 0) i++;
                else if (j < 0) j++;

                flag = -flag;
                break;
            }
        }
    }
    return ret;
}
int main(){
    vector<vector<int>> matrix = {
        { 1, 2, 3 ,1},
        { 4, 5, 6 ,2},
        { 7, 8, 9 ,1},
    };
    findDiagonalOrder(matrix);
    return 0;
}
