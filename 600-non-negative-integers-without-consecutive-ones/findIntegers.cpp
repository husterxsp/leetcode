/*
    dp[i] 表示 二进制位为i位的<=num的满足题意的数的个数
    [Min[i], Max[i]] 表示二进制位为i位时的最小和最大值，一般为[1000..., 101010...]
*/
class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(32), Max(32), Min(32);
        dp[0] = dp[1] = 1;
        Max[0] = Min[0] = 0;
        Max[1] = Min[1] = 1;

        int i;
        for (i = 2; i < 32; i++) {
            Min[i] = 1<<(i - 1);
            Max[i] = Min[i] + Max[i - 2];

            for (int j = 0; j < i - 1; j++) dp[i] += dp[j];

            if (num <= Max[i]) break;
        }

        int curMin = Min[i] + Min[i - 2], k = i - 2;
        while (k >= 0) {
            if (num <= curMin) {
                dp[i] -= dp[k];
                if (num == curMin) {
                    dp[i]++;
                    break;
                }

                curMin += Min[k - 1] - Min[k];
                k--;
            }
            else {
                k -= 2;
                curMin += Min[k];
            }
        }

        int ret = dp[i--];
        while (i >= 0) ret += dp[i--];
        return ret;
    }
};
