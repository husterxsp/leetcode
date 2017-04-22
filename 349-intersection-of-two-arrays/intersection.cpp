#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> mySet1, mySet2;
    for (auto num : nums1) mySet1.insert(num);
    for (auto num : nums2) mySet2.insert(num);

    vector<int> ret;
    for (auto num : mySet1) {
        if (mySet2.find(num) != mySet2.end()) ret.push_back(num);
    }

    return ret;
}

int main() {
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    intersection(nums1, nums2);
    return 0;
}
