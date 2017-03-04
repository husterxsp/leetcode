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
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++) {
        if (myMap.count(nums[i])) {
            if (i - myMap[nums[i]] <= k) {
                return true;
            }
            else {
                myMap[nums[i]] = i;
            }
        }
        else {
            myMap.insert(make_pair(nums[i], i));
        }
    }
    return false;
}

int main () {
    vector<int> nums = {1,2,3,4,5,1};
    cout << containsNearbyDuplicate(nums, 5) << endl;
    return 0;
}
