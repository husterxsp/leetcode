/*
    思路：遍历两遍，分别取得左边和右边的最大高度
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeight = 0, ret = 0, n = height.size();
        if (n <= 2) return 0;

        vector<int> container(n);

        // 左边最大高度
        for (int i = 0; i < height.size(); i++) {
            container[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        maxHeight = 0;
        // 右边最大高度
        for (int i = n - 1; i >= 0; i--) {
            container[i] = min(container[i], maxHeight);
            ret += (container[i] - height[i] > 0) ? (container[i] - height[i]) : 0;
            maxHeight = max(maxHeight, height[i]);
        }
        return ret;
    }
};
