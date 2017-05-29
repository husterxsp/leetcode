#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
/**
 14/27, TLE
 */
int splitArray(vector<int>& nums, int m) {
    if (m == 1) return accumulate(nums.begin(), nums.end(), 0);

    int ret = INT_MAX;
    int n = nums.size();
    for (int i = 0; i + m <= n; i++) {
        vector<int> newNums(nums.begin() + i + 1, nums.end());
        int sum = accumulate(nums.begin(), nums.begin() + i + 1, 0);
        ret = min(ret, max(sum, splitArray(newNums, m - 1)));
    }
    return ret;
}

/**

*/




int main() {
    vector<int> nums = {7,2,5,10,8};
    cout << splitArray(nums, 3) << endl;
    return 0;
}
