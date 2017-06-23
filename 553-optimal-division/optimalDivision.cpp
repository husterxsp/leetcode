class Solution {
public:
    // 放弃抵抗。。
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (!n) return "";

        string ret = to_string(nums[0]);
        if (n == 1) return ret;
        if (n == 2) return ret + "/" + to_string(nums[1]);

        ret += "/(" + to_string(nums[1]);

        for (int i = 2; i < n; i++) ret += "/" + to_string(nums[i]);
        return ret + ")";
    }
};
