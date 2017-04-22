#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3},
    };
    cout << maxSumSubmatrix(matrix, 2) << endl;
    return 0;
}
