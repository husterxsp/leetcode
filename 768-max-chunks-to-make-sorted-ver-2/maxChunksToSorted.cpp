// 和769相比多加一个等号，curMax <= minRight[i + 1]
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        vector<int> minRight(n + 1, INT_MAX);

        for (int i = n - 1; i >= 0; i--) {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }

        int ret = 0, curMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, arr[i]);
            if (curMax <= minRight[i + 1]) {
                ret++;
                curMax = INT_MIN;
            }
        }

        return ret;
    }
};
