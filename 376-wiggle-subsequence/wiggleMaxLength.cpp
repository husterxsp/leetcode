#include <iostream>
#include <vector>

using namespace std;
/**
    列出一些数就可以简单的找到规律了。。
*/
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;
    vector<int> diff;
    for (int i = 1; i < n; i++) diff.push_back(nums[i] - nums[i - 1]);
    for (int i = 1; i < diff.size(); i++) {
        if ((diff[i - 1] < 0 && diff[i] > 0) || (diff[i - 1] > 0 && diff[i] < 0)) continue;

        diff[i] += diff[i - 1];
        diff.erase(diff.begin() + i - 1);

        i--;
    }
    if (!diff.empty() && diff.back() == 0) diff.pop_back();
    return diff.size() + 1;
}

int main () {
    vector<int> nums = {84};
    cout << wiggleMaxLength(nums) << endl;
    return 0;
}
