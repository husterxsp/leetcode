class Solution {
public:
    // 洗牌算法
    vector<int> v;
    Solution(vector<int> nums) {
        v = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = v.size();
        vector<int> ret = v;
        // 这两种写法都能AC，但是有啥区别么。。概率是一样的么？
        // for (int i = 0; i < n; i++) swap(ret[i], ret[rand() % n]);
        for (int i = 0; i < n; i++) swap(ret[i], ret[i + rand() % (n - i)]);
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
