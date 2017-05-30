/**
    不会。.题目中的信息1 ≤ a[i] ≤ n (n = size of array)应当关注，是解题点
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // nums[i]: 1~n
            // nums[i]-1: 0~n-1 
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) ret.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return ret;
    }
};
