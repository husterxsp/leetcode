class Solution {
public:
    int search(vector<vector<int>>& ret, vector<int> nums, int pos, vector<int> cur) {
        if (cur.size() > 1) ret.push_back(cur);

        for (int i = pos; i < nums.size(); i++) {
            if (cur.empty() || nums[i] >= cur.back()) {
                cur.push_back(nums[i]);
                search(ret, nums, i + 1, cur);
                cur.pop_back();
            }
        }

        return 0;
    }
    /**
        注意这种写法不对 unordered_set<vector<int>> mySet; 还要自己写hash函数？
        https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
    */
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        search(ret, nums, 0, {});
        // 数组去重
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
