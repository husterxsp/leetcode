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
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> mySet;
    for (int i = 0; i < nums.size();i++) {
        if (mySet.count(nums[i])) return true;
        mySet.insert(nums[i]);
    }
    return false;
}

int main () {
    vector<int> nums = {1,1};
    cout << containsDuplicate(nums) << endl;
    return 0;
}
