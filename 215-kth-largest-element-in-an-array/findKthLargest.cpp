#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
// 这样也能AC...
// int findKthLargest(vector<int>& nums, int k) {
//     sort(nums.begin(), nums.end());
//     reverse(nums.begin(), nums.end());
//     return nums[k];
// }

//解法二：快速选择
int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned)time(NULL));

    int pivot = nums[rand() % nums.size()];
    vector<int> nums1, nums2;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > pivot) {
            nums1.push_back(nums[i]);
        }
        else if (nums[i] < pivot) {
            nums2.push_back(nums[i]);
        }
    }

    if (k <= nums1.size()) {
        return findKthLargest(nums1, k);
    }
    else if (k > nums.size() - nums2.size()) {
        return findKthLargest(nums2, k - (nums.size() - nums2.size()));
    }
    return pivot;
}

int main () {
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, 2) << endl;
    return 0;
}
