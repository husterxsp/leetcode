#include <iostream>
#include <vector>

// candidates无重复，每个数能用多次
using namespace std;
void find(vector<int>& candidates, int start, int target, vector<int>& sum, vector<vector<int>>& allSum) {
    if (target == 0) {
        allSum.push_back(sum);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            sum.push_back(candidates[i]);
            find(candidates, i, target - candidates[i], sum, allSum);
            sum.pop_back();
        }
        else {
            break;
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> allSum;
    vector<int> sum;
    sort(candidates.begin(), candidates.end());
    if (candidates.empty()) return allSum;
    find(candidates, 0, target, sum, allSum);
    return allSum;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    combinationSum(candidates, 7);
    return 0;
}
