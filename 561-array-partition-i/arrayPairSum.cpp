class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0, n = nums.size() / 2;
        for (int i = 0; i < n; i++) ret += nums[i * 2];
        return ret;
    }
};
