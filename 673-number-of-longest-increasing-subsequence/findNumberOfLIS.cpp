/**
    参考：https://discuss.leetcode.com/topic/102974/c-dp-with-explanation-o-n-2/2
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ret = 0, maxLen = 1, n = nums.size();
        vector<int> cnt(n, 1), len(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;

                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        for (int i = 0; i < n; i++) if (len[i] == maxLen) ret += cnt[i];
        return ret;
    }
};
