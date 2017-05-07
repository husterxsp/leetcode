#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
void search(int k, int n, int level, vector<int>& out, vector<vector<int>>& ret) {
    if (n < 0 || k < 0) return;
    if (k == 0 && n == 0) ret.push_back(out);

    for (int i = level; i <= 9; i++) {
        out.push_back(i);
        search(k - 1, n - i, i + 1, out, ret);
        out.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ret;
    vector<int> out;

    search(k, n, 1, out, ret);
    return ret;
}

int main () {
    combinationSum3(3, 9);
    return 0;
}
