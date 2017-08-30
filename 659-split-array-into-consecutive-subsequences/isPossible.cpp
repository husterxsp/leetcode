/**
    参考：http://www.cnblogs.com/pk28/p/7384602.html
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        map<int, int> m, m1;
        for (int i = 0; i < n; i++) m[nums[i]]++;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            if (m[x] <= 0) continue;
            if (m1[x - 1]) {
                m[x]--;
                m1[x - 1]--; m1[x]++;
            }
            else if (m[x + 1] > 0 && m[x + 2] > 0) {
                m[x]--; m[x + 1]--; m[x + 2]--;
                m1[x + 2]++;
            }
            else return false;
        }
        return true;
    }
};
