#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int i = 1;
        int ret = 0;

        int p = 0;
        int n = nums.size();
        while (p < n) {
            if (nums[p] == target) {
                int choice = rand() % i++;
                if (choice == 0) ret = p;
            }
            p++;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main() {
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution obj = Solution(nums);
    int i = 0;
    while (i++ < 1000) {
        cout << obj.pick(3) << endl;
    }

    return 0;
}
