class Solution {
public:
    vector<int> getPostion(int num) {
        int D = num / 100;
        int P = (num % 100) / 10;
        int V = num % 10;
        return vector<int>{D, P, V};
    }
    int pathSum(vector<int>& nums) {
        int ret = 0, n = nums.size();
        vector<vector<int>> pos(n, vector<int>(3));

        for (int i = 0; i < n; i++) pos[i] = getPostion(nums[i]);

        for (int i = 0; i < n; i++) {
            int child = 0;
            for (int j = i + 1; j < n; j++) {
                if (pos[j][0] > pos[i][0] + 1) break;
                if (pos[j][0] == pos[i][0] + 1 && pos[j][1] >= pos[i][1] * 2 - 1 && pos[j][1] <= pos[i][1] * 2) {
                    child++;
                    pos[j][2] += pos[i][2];
                }
            }
            if (child == 0) ret += pos[i][2];
        }
        return ret;
    }
};
