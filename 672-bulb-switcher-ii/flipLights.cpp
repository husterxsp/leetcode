/*
    数学题，依旧是找规律，
    题目中的flip是toggle的意思，一开始以为只是关闭的意思
    参考：https://discuss.leetcode.com/topic/102033/java-o-1

    If we use button 1 and 2, it equals to use button 3.

    1 + 2 --> 3, 1 + 3 --> 2, 2 + 3 --> 1
    So, there are only 8 cases.

    All_on, 1, 2, 3, 4, 1+4, 2+4, 3+4
    And we can get all the cases, when n>2 and m>=3.
*/

// n >= 1 ?
class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0) return 1;
        if (m == 1) {
            if (n == 1) return 2;
            if (n == 2) return 3;
            return 4;
        }
        if (m == 2) {
            if (n == 1) return 2;
            if (n == 2) return 4;
            return 7;
        }
        // m >= 3
        if (n == 1) return 2;
        if (n == 2) return 4;
        return 8;
    }
};
