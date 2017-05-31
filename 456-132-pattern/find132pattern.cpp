#include <iostream>
#include <vector>

using namespace std;
/**
    能A,但是效率好像有点低
*/
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = i + 2;
        while (j < n - 1 && k < n) {
            if (nums[j] > nums[i] && nums[k] > nums[i] && nums[j] > nums[k]) return true;

            if (nums[k] <= nums[i]) {
                k++;
            }
            else {
                j = k;
                k = j + 1;
            }
        }
    }
    return false;
}
/**
    用栈
*/
int main() {
    vector<int> nums{-1, 3, 1, 0};
    cout << find132pattern(nums) << endl;
    return 0;
}
