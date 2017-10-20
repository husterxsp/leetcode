/**
    一开始for循环写成了i=0开始，总是超时，耽误不少时间
*/
class Solution {
public:
    bool help(vector<int> nums, int subSum, int curSum, int k, int start) {
        if (k == 0) return true;
        if (nums.size() < k) return false;

        // 删除这部分用时更短
        // multiset<int> mySet(nums.begin(), nums.end());
        // auto it = mySet.find(subSum - curSum);
        // if (it != mySet.end()) {
        //     mySet.erase(0);
        //     mySet.erase(it);
        //     nums = vector<int>(mySet.begin(), mySet.end());
        //     return help(nums, subSum, 0, k - 1, 0);
        // }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] == 0) continue;

            int tmp = nums[i];
            nums[i] = 0;

            curSum += tmp;

            if (curSum == subSum) {
                if (help(nums, subSum, 0, k - 1, 0)) return true;
            }
            else if (curSum < subSum) {
                if (help(nums, subSum, curSum, k, i + 1)) return true;
            }

            nums[i] = tmp;
            curSum -= tmp;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int subSum = sum / k;
        if (*max_element(nums.begin(), nums.end()) > subSum) return false;

        return help(nums, subSum, 0, k, 0);
    }
};
