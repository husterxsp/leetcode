#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
// 也能AC
// int maximumGap(vector<int>& nums) {
//     if (nums.size() < 2) return 0;
//     sort(nums.begin(). nums.end());
//     int gap = 0;
//     for (int i = 1; i < nums.size(); i++) {
//         gap = max(gap, nums[i] - nums[i - 1]);
//     }
//     return gap;
// }

int maximumGap(vector<int>& nums) {
    int n = (int)nums.size();
    if (n < 2) return 0;

    int maxNum = nums[0], minNum = nums[0];
    for (int i = 0; i < n; i++) {
        maxNum = max(maxNum, nums[i]);
        minNum = min(minNum, nums[i]);
    }
    // 每个桶的长度
    int len = (maxNum - minNum) / n + 1;
    // 桶的个数
    int bucketsNum = (maxNum - minNum) / len + 1;
    vector<vector<int>> buckets(bucketsNum);

    for (int i : nums) {

        int j = (i - minNum) / len;

        if (buckets[j].empty()) {
            buckets[j].push_back(i);
            buckets[j].push_back(i);
        }
        else {
            if (i < buckets[j][0]) buckets[j][0] = i;
            if (i > buckets[j][1]) buckets[j][1] = i;
        }
    }

    int gap = 0;

    // 因为中间回跳过一些桶，所以需要个prev来保存上一个不为空的桶。
    int prev = 0;
    for (int i = 1; i < bucketsNum; i++) {
        if (buckets[i].empty()) continue;
        gap = max(gap, buckets[i][0] - buckets[prev][1]);
        prev = i;
    }

    return gap;
}


int main () {
    vector<int> nums = {1, 1, 1, 1};
    cout << maximumGap(nums) << endl;
    return 0;
}
