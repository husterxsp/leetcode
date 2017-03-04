#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n == 0 ? 0 : nums[0];

    vector<int> money(n, 0);
    money[0] = nums[0];
    money[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        money[i] = max(money[i - 2] + nums[i], money[i - 1]);
    }
    return money[n - 1];
}

int main () {
    vector<int> nums = {2, 1};
    cout << rob(nums) << endl;
    return 0;
}
