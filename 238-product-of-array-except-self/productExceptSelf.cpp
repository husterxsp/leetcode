#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    vector<int> ret(n);

    for (int i = 1; i < n; i++) {
        left[i] = nums[i - 1] * left[i - 1];
        right[n - i - 1] = nums[n - i] * right[n - i];
    }
    for (int i = 0; i < n; i++) {
        ret[i] = left[i] * right[i];
    }
    return ret;
}
int main () {
    vector<int> nums = {1, 2, 3, 4};
    productExceptSelf(nums);
    return 0;
}
