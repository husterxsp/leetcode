/**
    TLE...
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bitset<32> b(nums[i] ^ nums[j]);
                ret += b.count();
            }
        }
        return ret;
    }
};
/**
    找规律。。什么鬼。。
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int num : nums) {
                if ((1 << i) & num) count++;
            }
            ret += count * (n - count);
        }
        return ret;
    }
};
