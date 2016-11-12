#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1, mid=0, res=0;
    while(left <= right){
        if(target > nums[right]){
            return right+1;
        }
        if(target < nums[left]){
            return left;
        }
        mid = (left+right)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(left == right && res){
            break;
        }
        if(nums[mid] > target){
            right = mid-1;
            res = right;
        } else {
            left = mid+1;
            res = left;
        }
    }
    if(res < 0){
        res = 0;
    }
    return res;
}

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(10);
    cout << searchInsert(nums, 8);
    return 0;
}
