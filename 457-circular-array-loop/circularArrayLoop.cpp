/**
    O(n^2)时间，O(n)空间，待优化
*/
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int len = nums[i];
            int type = nums[i] > 0 ? 1 : -1;

            if (abs(len) % n == 0) continue;
            vector<int> vis(n);
            while (1) {
                int pos = (i + len + n) % n;

                if (nums[pos] * type < 0 || vis[pos]) break;

                len = (len + nums[pos]) % n;
                vis[pos] = 1;

                if (abs(len) % n == 0) return true;
            }
        }
        return false;
    }
};
