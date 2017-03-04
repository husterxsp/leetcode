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
int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0, ret = 0, left = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum < s && right < nums.size() + 1) {
            right++;
            sum += nums[right];
        }
        while (sum - nums[left] >= s) {
            sum -= nums[left];
            left++;
        }
        ret = ret == 0 ? right - left + 1 : min(ret, right - left + 1);
    }
    if (sum < s) return 0;
    return ret;
}
int main () {
    vector<int> nums = {1,1};
    cout << minSubArrayLen(3, nums) << endl;
    return 0;
}
