class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        if (!m) return nums;
        int n = nums[0].size();

        vector<int> allNums;
        for (int i = 0; i < m; i++) allNums.insert(allNums.end(), nums[i].begin(), nums[i].end());
        if (m * n != r * c) return nums;

        vector<vector<int>> ret;
        int pos = 0;
        for (int i = 0; i < r; i++) {
            ret.push_back(vector<int>(allNums.begin() + pos, allNums.begin() + pos + c));
            pos += c;
        }
        return ret;
    }
};
