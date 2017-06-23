class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) continue;
            int index = nums[i], cur = 1;
            nums[i] = -1;
            while (index != i) {
                int tmp = nums[index];
                nums[index] = -1;
                index = tmp;
                cur++;
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};
