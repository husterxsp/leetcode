#include <iostream>
#include <vector>
using namespace std;

// 思路：参考 T40 combinationSum
void findCombine(vector<int>& com, vector<vector<int>>& allCom, int start, int n, int k) {
    if (com.size() == k) {
        allCom.push_back(com);
        return;
    }
    for (int i = start; i <= n; i++) {
        com.push_back(i);
        findCombine(com, allCom, i + 1, n, k);
        com.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> allCom;
    vector<int> com;
    if (k <= 0 || k > n) return allCom;
    findCombine(com, allCom, 1, n, k);
    return allCom;
}

int main(){
    combine(4, 3);
    return 0;
}
