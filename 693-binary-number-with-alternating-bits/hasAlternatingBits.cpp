class Solution {
public:
    bool hasAlternatingBits(int n) {
        int mask = 1, prev;

        prev = n & mask;
        n >>= 1;
        while (n > 0) {
            int cur = n & mask;
            if (cur == prev) return false;
            n >>= 1;
            prev = cur;
        }
        return true;
    }
};
