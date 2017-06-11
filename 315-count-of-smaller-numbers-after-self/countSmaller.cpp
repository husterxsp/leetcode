#include <iostream>
#include <vector>

using namespace std;
/**
    参考网上解，http://blog.csdn.net/qq508618087/article/details/51320926
    解法1， 从右往左搜索，并将搜索过的放入一个有序数组
*/
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ret(n, 0), tmp;
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(tmp.begin(), tmp.end(), nums[i]);
        ret[i] = it - tmp.begin();
        tmp.insert(it, nums[i]);
    }
    return ret;
}
/**
    解法2. 归并排序
*/


/**
    解法3. 二叉索引树
    参考：https://www.hrwhisper.me/leetcode-count-of-smaller-numbers-after-self/
*/
// vector<int> countSmaller(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> tmp = nums;
//     sort(tmp.begin(), tmp.end());
//
//     unordered_map<int, int> myMap;
//     for (int i = 0; i < tmp.size(); i++) {
//         myMap[tmp[i]] = i + 1;
//     }
//     vector<int> ret(n, 0);
//     for (int i = n - 1; i >= 0; i--) {
//         ret[i] =
//     }
//
//     return ret;
// }


int main () {
    vector<int> nums{5, 2, 6, 1};
    countSmaller(nums);
    return 0;
}
