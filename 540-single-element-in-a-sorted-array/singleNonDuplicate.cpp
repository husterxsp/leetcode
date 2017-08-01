/**
    解法1：位运算，O(N)，跟之前做过的一样，但是需要注意的是本题多了一个条件排序没有用
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) ret ^= num;
        return ret;
    }
};
/**
    解法二：充分利用排序的条件
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        
        return ret;
    }
};
