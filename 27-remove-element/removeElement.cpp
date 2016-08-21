#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    if(nums.size() == 0){
        return 0;
    }
    int len = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != val) {
            nums[len++] = nums[i];
        }
    }
    return len;
}
int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    cout << removeElement(nums, 3);
    return 0;
}