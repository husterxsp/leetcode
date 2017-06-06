class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /**
            push一个0是为了处理最后一个元素刚好是1的情况，
            但是其实通过[]来访问，即使访问越界也不会报错，只不过访问的内容是随机的
        */
        nums.push_back(0);
        int ret = 0, cur = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ret = max(ret, cur);
                cur = 0;
            }
            else {
                cur++;
            }
        }
        return ret;
    }
};
