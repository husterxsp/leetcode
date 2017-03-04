#include <iostream>
#include <vector>

// candidates有重复，但每个数只能用一次
// 注意去重部分，如[1, 1, 2, 5] 重复的是start=0, i=1
using namespace std;
void find(vector<int>& candidates, int start, int target, vector<int>& sum, vector<vector<int>>& allSum) {
    if (target == 0) {
        allSum.push_back(sum);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if(i > start && candidates[i] == candidates[i-1]) continue;
        if (candidates[i] <= target) {
            sum.push_back(candidates[i]);
            find(candidates, i + 1, target - candidates[i], sum, allSum);
            sum.pop_back();
        }
        else {
            break;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> allSum;
    vector<int> sum;
    sort(candidates.begin(), candidates.end());
    if (candidates.empty()) return allSum;
    find(candidates, 0, target, sum, allSum);
    return allSum;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    combinationSum2(candidates, 8);
    return 0;
}
