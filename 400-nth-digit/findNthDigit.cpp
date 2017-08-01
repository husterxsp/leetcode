/**
    需要注意power设置为int会溢出
*/
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        n = n - 9;
        int k = 2;
        long power = 10;
        while (n > k * power * 9) {
            n -= k * power * 9;
            k++;
            power *= 10;
        }
        if (n % k == 0) return (power + n / k - 1) % 10;
        return to_string(power + n / k)[n % k - 1] - '0';
    }
};
