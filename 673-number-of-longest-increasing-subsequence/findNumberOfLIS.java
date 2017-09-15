class Solution {
    public int findNumberOfLIS(int[] nums) {
        int ret = 0, maxLen = 1, n = nums.length;

        int[] cnt = new int[n], len = new int[n];;

        Arrays.fill(cnt, 1);
        Arrays.fill(len, 1);

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
            maxLen = Math.max(maxLen, len[i]);
        }
        for (int i = 0; i < n; i++) if (len[i] == maxLen) ret += cnt[i];
        return ret;
    }
}
