#include <iostream>
#include <algorithm>
#include <vector>
#include <Map>
using namespace std;

// 错解
//[1,3,2] -> [2,3,1](error), [2,1,3](right)
// 这算法是自己想的还是？。。。
// void nextPermutation(vector<int>& nums) {
//     bool get = false;
//     for(int i=nums.size()-1;i>=1;i--){
//         for(int j=i-1;j>=0;j--){
//             if(nums[i] > nums[j]){
//                 get = true;
//                 int tmp = nums[i];
//                 nums[i] = nums[j];
//                 nums[j] = tmp;
//                 break;
//             }
//         }
//         if(get){
//             break;
//         }
//     }
//     if(!get){
//         reverse(nums.begin(), nums.end());
//     }
// }

// 正解AC
// 注意边界条件测判断啊！！！是>还是>=之类。
// 此题应当注意完全升序，完全降序，以及序列中有相等值等情况。
void nextPermutation(vector<int>& nums){
    int i = nums.size()-2;
    while (i>=0 && nums[i] >= nums[i+1]) {
        i--;
    }
    if(i >= 0){
        int j = i+1;
        while (j<nums.size() && nums[j]>nums[i]) {
            j++;
        }
        swap(nums[i], nums[j-1]);
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> a = {1,2,1,5};
    nextPermutation(a);
    return 0;
}
