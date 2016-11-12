#include <iostream>
#include <vector>

using namespace std;
int minSteps;

// 超时。
//void jumpStep(vector<int>& nums, int curPos, int steps){
//
//    if(curPos >= nums.size()-1){
//        if(steps < minSteps){
//            minSteps = steps;
//            return;
//        }
//    }
//    if(steps > minSteps){
//        return;
//    }
//    for(int i=nums[curPos];i>=1;i--){
//        jumpStep(nums, curPos+i, steps+1);
//    }
//}
//
//int jump(vector<int>& nums) {
//    minSteps = nums.size();
//    jumpStep(nums, 0, 0);
//    return minSteps;
//}

// 参考网上的解法，思路：循环数组一遍，每一步均记录最大距离cur,同时判断。。。
// http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
int jump(vector<int>& nums) {
    int ret = 0;
    int last = 0;
    int curr = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (i > last) {
            last = curr;
            ++ret;
        }
        curr = max(curr, i+nums[i]);
    }

    return ret;
}

int main() {
    vector<int> nums = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    cout << jump(nums);
    return 0;
}
