/**
    n = 1 + k + k^2 + k^3 + k^4 + … + k^(m-1) = (k^m - 1) / k - 1
    等比数列
    由公式可以看出 m越大k越小
    因为题目中有k>=2,所以可以计算出 m <= log2(n + 1) = log(n + 1)/log(2)
    另外，n > k^(m - 1)，可以得出 k < n^( 1/(m - 1) );

    参考：http://www.cnblogs.com/grandyang/p/6620351.html
*/
class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stol(n);
        for (int i = log(num + 1)/log(2); i >= 2; i--) {
            // 因为pow的时候有误差，所以加个1?
            long left = 2, right = pow(num, 1.0 / (i - 1)) + 1;
            while (left < right) {
                long k = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; j++) {
                    // 注意这里的计算，如果用乘方，然后再一个个加感觉会耗时一些
                    sum = sum * k + 1;
                }

                if (sum == num) return to_string(k);
                else if (sum < num) left = k + 1;
                else right = k;
            }
        }
        return to_string(num - 1);
    }
};
