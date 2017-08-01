/**
    注意乘法可能溢出
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= sqrt(c); a++) {
            int b = sqrt(c - a * a);
            if (a * a + b * b == c) return true;
        }
        return false;
    }
};
