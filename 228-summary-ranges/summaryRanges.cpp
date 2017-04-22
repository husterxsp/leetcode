#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    int count = nums.size();
    if (count == 0) return ret;
    int prev = 0;
    for (int i = 1; i <= count; i++) {
        if (i < count && nums[i] - nums[i - 1] == 1) continue;
        string tmp = to_string(nums[prev]);
        if (prev != i - 1) {
            tmp += "->" + to_string(nums[i - 1]);
        }
        ret.push_back(tmp);
        prev = i;
    }
    return ret;
}

int main () {
    vector<int> arr = {7};
    summaryRanges(arr);
    return 0;
}
