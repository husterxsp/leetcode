#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool jump(int k, vector<int>& nums){
    if(k+1 == nums.size()){
        return true;
    }
    if(k+1 > nums.size()){
        return false;
    }
    if(nums[k] == 0){
        return false;
    }
    for(int i=nums[k];i>0;i--){
        if(jump(k+i, nums)){
            return true;
        }
    }
    return false;
}

// 解法一：递归，尝试对每一步都遍历直到刚好到达最后一个，但实际上只要最大的值超过最后一个就行。
// 此方法遍历过多，超时
bool canJump(vector<int>& nums) {
    return jump(0, nums);
}

// 解法二，每步均取最大值，若此最大值小于当前步数，则失败。
bool canJump2(vector<int> A) {
    int tmpMax = 0;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (i > tmpMax) return false;
        if (tmpMax < i + A[i])
            tmpMax = i + A[i];
    }
    return true;
}

int main(){
    vector<int> nums = {5,4,0,0,1};
    cout << canJump(nums);
    return 0;
}
