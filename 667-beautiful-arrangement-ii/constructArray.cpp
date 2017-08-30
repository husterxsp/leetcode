/*
    参考：https://discuss.leetcode.com/topic/101113/c-java-clean-code-4-liner
*/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        for (int i = 1, j = n; i <= j;) {
            if (k > 1) {
                ret.push_back(k % 2 ? i++ : j--);
                k--;
            }
            else ret.push_back(i++);
        }
        return ret;
    }
};
