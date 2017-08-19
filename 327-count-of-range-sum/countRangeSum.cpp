/**
    native solution: O(n^2)
    需要注意用long，否则求和会溢出
*/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), ret = 0;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= lower && sum <= upper) ret++;
            }
        }
        return ret;
    }
};
/**
    参考: http://www.cnblogs.com/grandyang/p/5162678.html

    lower <= sum[i] - sum[j] <= upper
    sum[i] - upper =< sum[j] <= sum[i] - lower

    该解法的优化点：利用了multiset排好序
*/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), ret = 0;
        long sum = 0;
        // 插入一个0，表示sum[i] - 0, 即sum[i]
        multiset<long> mySet{0};

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ret += distance(mySet.lower_bound(sum - upper), mySet.upper_bound(sum - lower));
            mySet.insert(sum);
        }
        return ret;
    }
};

/**
    Merge Sort
*/
