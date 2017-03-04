#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> mySet;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) mySet.erase(nums[i - k - 1]);
        //|x - nums[i]| <= t
        // x - nums[i] <= t || x - nums[i] >= -t;
        // x >= nums[i] - t;
        long long diff = (long long)nums[i] - (long long)t;
        auto pos = mySet.lower_bound(diff);
        long long tmp = (long long)*pos - (long long)nums[i];
        if (pos != mySet.end()) {
            if (abs(tmp) <= t) return true;
        }
        mySet.insert(nums[i]);
    }
    return false;
}

int main () {
    // false
    vector<int> nums = {-2147483648, -2147483647};
    cout << containsNearbyAlmostDuplicate(nums, 3, 3) << endl;
    return 0;
}
