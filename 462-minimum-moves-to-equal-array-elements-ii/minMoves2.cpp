/**
    一开始想的是平均数。。。其实应该是中位数。。。
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0, mid = nums[nums.size() / 2];

        for (auto num : nums) {
            ret += abs(num - mid);
        }
        return ret;
    }
};
