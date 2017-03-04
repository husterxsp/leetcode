#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// O(n)
// int search(vector<int>& nums, int target) {
//     for(int i=0;i<nums.size();i++){
//         if(nums[i] == target){
//             return i;
//         }
//     }
//     return -1;
// }

// O(logn)
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        // 注意这个地方的等于，上面的mid四舍五入取下。
        if(nums[mid] >= nums[left]) {
            if (nums[left] <= target && target <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] <= target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    cout << search(nums, 2);
    return 0;
}
