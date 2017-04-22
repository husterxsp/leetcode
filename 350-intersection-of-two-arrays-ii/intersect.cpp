#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> myMap1, myMap2;
    for (auto num : nums1) myMap1[num]++;
    for (auto num : nums2) myMap2[num]++;

    vector<int> ret;
    for (auto itor : myMap1) {
        int num = itor.first;
        if (myMap2.find(num) != myMap2.end()) {
            ret.insert(ret.end(), min(myMap1[num], myMap2[num]), num);
        }
    }
    return ret;
}

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {};
    intersect(nums1, nums2);
    return 0;
}
