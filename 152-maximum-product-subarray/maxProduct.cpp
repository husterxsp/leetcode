#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 要求：找到连续的子序列，乘积最大
// 提示是动态规划，怎么动规？。。yi
// 既然是乘积，那是不是可以考虑连续最大子序列，负数的个数为偶数？
// 输入可能含 0 吗？
// int maxProduct(vector<int>& nums) {
//     int n = nums.size(), max = nums[0], min = nums[0], cur;
//     vector<int> arr;
//     for (int i = 1; i < n; i++) {
//         if (nums[i] == 0 || nums[i - 1] == 0) continue;
//         nums[i] *= nums[i - 1];
//     }
//     for (int i = 0; i < n; i++) {
//         cout << nums[i] << " ";
//     }
//     return 0;
// }

int maxProduct(vector<int>& nums) {
    int n = nums.size(), maxP = nums[0], minP = nums[0], ret = nums[0];
    vector<int> arr;
    for (int i = 1; i < n; i++) {
        int tmpMax = maxP, tmpMin = minP;
        maxP = max(nums[i], max(tmpMin * nums[i], tmpMax * nums[i]));
        minP = min(nums[i], min(tmpMin * nums[i], tmpMax * nums[i]));
        ret = max(ret, maxP);
    }
    return ret;
}

int main() {
    vector<int> a = {2, 0};
    cout << maxProduct(a) << endl;
    return 0;
}
