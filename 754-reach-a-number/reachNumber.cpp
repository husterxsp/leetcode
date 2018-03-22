/**
    找规律的题？
    参考：https://leetcode.com/articles/reach-a-number/
    S = 1 + 2 + ... + k >= target
    delta = S - target;
    1. 当 delta 为偶数时，delta/2为整数，此时必定有 m < k,使得 m = delta/2。
    那么将m的符号置反，则相当于  S-2m，此时等于 target。 故此时直接return k
    2. 当delta 为奇数时，考虑在S中再加入一个数 k+1,此时 delta = delta + k + 1,
    如果 delta + k + 1 为偶数，则按照1的方法，可以返回 k+1,
    否则，再加一个数 k+2,此时 delta + k + 1 + k + 2 必定是偶数，返回 k+2
*/

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);

        int S = 0, n = 0;
        while (S < target) S += ++n;

        int delta = S - target;
        if (delta % 2 == 0) return n;

        return (n + 1) % 2 == 1 ? n + 1 : n + 2;
    }
};
