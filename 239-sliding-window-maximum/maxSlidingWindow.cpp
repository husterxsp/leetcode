#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
/**
    也能AC,但效率较低，max_element也是通过元素比较
*/
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     deque<int> myDeque;
//     vector<int> ret;
//     int n = nums.size();
//     int i = 0;
//
//     if (n <= 0) return ret;
//     while (i < k) {
//         myDeque.push_back(nums[i++]);
//     }
//     ret.push_back(*max_element(myDeque.begin(), myDeque.end()));
//     while (i < n) {
//         myDeque.pop_front();
//         myDeque.push_back(nums[i++]);
//         ret.push_back(*max_element(myDeque.begin(), myDeque.end()));
//     }
//     return ret;
// }

// 改进,参考网上的解法，
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> myDeque;
    vector<int> ret;
    int n = nums.size();
    if (n <= 0) return ret;

    for (int i= 0; i < n; i++) {
        if (!myDeque.empty() && myDeque.front() == i - k) myDeque.pop_front();
        while (!myDeque.empty() && nums[myDeque.back()] < nums[i]) {
            myDeque.pop_back();
        }
        myDeque.push_back(i);
        if (i >= k - 1) ret.push_back(nums[myDeque.front()]);
    }
    return ret;
}

int main () {
    vector<int> nums = {};
    maxSlidingWindow(nums, 3);
    return 0;
}
