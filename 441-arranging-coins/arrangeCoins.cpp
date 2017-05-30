class Solution {
public:
    /**
        x * (x + 1) / 2 <= n
    */
    int arrangeCoins(int n) {
        return (sqrt(8 * (long)n + 1) - 1) / 2;
    }
};
