#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//思路一：找到target向两边分别遍历，但是最差情况比如全部为target时间复杂度O(n)
//思路二：用两个二分分别找出左右边界
//二分查找变种？。。
int searchLeft(vector<int>& nums, int target){
    int left = 0, right = nums.size()-1, mid=0;
    while(left <= right){
        mid = (left+right)/2;
        if(target > nums[mid]){
            left = mid+1;
        } else if(target < nums[mid]){
            right = mid-1;
        } else {
            right = mid-1;
            // 死循环
            // right = mid;
        }
    }
    if(left>=0 && left <= nums.size()-1 && nums[left] == target) return left;
    return -1;
}
int searchRight(vector<int>& nums, int target){
    int left = 0, right = nums.size()-1, mid=0;
    while(left <= right){
        mid = (left+right)/2;
        if(target > nums[mid]){
            left = mid+1;
        } else if(target < nums[mid]){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if(right>=0 && right <= nums.size()-1 && nums[right] == target) return right;
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret;
    ret.push_back(searchLeft(nums, target));
    ret.push_back(searchRight(nums, target));
    return ret;
}

int main(){
    vector<int> nums = {5,7,7,7,10};
    searchRange(nums, 8);
    return 0;
}
