#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1){
        return nums.size();
    }
    vector<int>::iterator prev, cur;
    prev = nums.begin();
    cur = nums.begin() + 1;
    for (; cur != nums.end(); cur++) {
        if(*cur == *prev){
            nums.erase(cur);
            cur--;
        } else {
            prev++;
        }
    }
    return nums.size();
}

int removeDuplicates2(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int len = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[len] != nums[i]) {
            nums[++len] = nums[i];
        }
    }
    return len + 1;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    cout << removeDuplicates(nums);
    return 0;
}