#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
int rob(vector<int>& nums, int offset) {
    int n = (int)nums.size();
    if (n <= 1) return n == 0 ? 0 : nums[0];

    vector<int> money(n - 1, 0);
    money[0] = nums[0 + offset];
    money[1] = max(nums[0 + offset], nums[1 + offset]);
    for (int i = 2 + offset; i < n - 1 + offset; i++) {
        money[i - offset] = max(money[i - 2 - offset] + nums[i], money[i - 1 - offset]);
    }
    return money[n - 2];
}
int rob(vector<int>& nums) {
    return max(rob(nums, 0), rob(nums, 1));
}

int main () {
    vector<int> nums = {2, 1, 4};
    cout << rob(nums) << endl;
    return 0;
}
