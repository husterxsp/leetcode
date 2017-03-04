#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    // 理解这一步最关键 k = k % n;
    k = k % n;
    for (int i = 0; i < n - k; i++) {
        nums.push_back(nums[0]);
        nums.erase(nums.begin());
    }
}
int main () {
    vector<int> nums = {1, 2};
    rotate(nums, 3);
    return 0;
}
