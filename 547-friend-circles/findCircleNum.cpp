#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;
/**
    思路：构造 weighted union-find 树
*/

int root(vector<int> vec, int i) {
    while (i != vec[i]) {
        // 路径压缩
        vec[i] = vec[vec[i]];
        i = vec[i];
    }
    return i;
}
void quickUnion(vector<int> &vec, vector<int> &sz, int i, int j, unordered_set<int> &ret) {
    int r1 = root(vec, i), r2 = root(vec, j);
    if (r1 == r2) return;

    if (sz[r1] < sz[r2]) {
        vec[r1] = r2;
        sz[r2] += sz[r1];
        ret.erase(r1);
    }
    else {
        vec[r2] = r1;
        sz[r1] += sz[r2];
        ret.erase(r2);
    }
}
int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    vector<int> vec(n), sz(n, 1);
    for (int i = 0; i < n; i++) vec[i] = i;

    unordered_set<int> ret(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (M[i][j] == 1) quickUnion(vec, sz, i, j, ret);
        }
    }

    return ret.size();
}

int main() {
    vector<vector<int>> M = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    cout << findCircleNum(M) << endl;
    return 0;
}
