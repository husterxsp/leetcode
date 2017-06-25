/**
    解法1：建立累加和数组
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n) return 0;

        // sum(n) 代表 左闭右开区间[0, n）的和
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (sum[j + 1] - sum[i] == k) ret++;
            }
        }
        return ret;
    }
};

/**
    解法2：http://www.cnblogs.com/grandyang/p/6810361.html
    直接看代码好了，，解释看不懂。。。
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0, sum = 0, n = nums.size();
        unordered_map<int, int> myMap;

        // sum 刚好等于k的时候，myMap[sum - k] = myMap[0] = 1
        myMap[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // myMap[sum - k] 表示以当前位置i为结束点往前看，和为k的区间个数
            ret += myMap[sum - k];
            myMap[sum]++;
        }

        return ret;
    }
};
