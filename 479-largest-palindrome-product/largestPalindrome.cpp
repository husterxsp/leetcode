/**
A不动。。
1. 没啥规律，虽然看起来（99,91）,(9999, 9901)像是有啥规律
    9,1
    99,91
    995,583(应该是993, 913)
    9999,9901
2. 尝试两层循环，例如n=3, i, j 分别从999遍历到100，找到回文数就退出。。。
但是这种算法找到的是（995，583），而乘积最大的应该是（993，913）。。。ORZ。。。

参考discuss解答
*/
class Solution {
public:
    long createPalindrom(int half) {
        string tmp = to_string(half);
        reverse(tmp.begin(), tmp.end());
        return stol(to_string(half) + tmp);
    }
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upperBound = pow(10, n) - 1, lowerBound = pow(10, n - 1);
        long maxNum = (long)upperBound * (long)upperBound;

        int half = (int) (maxNum / (long)pow(10, n));

        bool found = false;
        long palindrom = 0;
        while (!found) {
            palindrom = createPalindrom(half);

            for (long i = upperBound; i >= lowerBound && i * i >= palindrom; i--) {
                if (palindrom % i == 0) {
                    found = true;
                    break;
                }
            }
            half--;
        }
        return (int) (palindrom % 1337);
    }
};
