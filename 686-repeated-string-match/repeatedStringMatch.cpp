/**
    思路：通过旋转A(或者B) 来找到对应相等的位置。
    考虑几种情况：
    A: abcd  B: abcdab  不需要旋转, 返回 2
    A: abcd  B: dabcd 旋转后A: dabc  B: dabcd， 返回 2
    A: abcd  B: dabcdab 旋转后A: dabc  B: dabcdab, 返回 3
*/
class Solution {
public:
    int check(string A, string B, int lenA, int lenB, int reverseStr) {
        int ret = 0;
        for (int i = 0; i < lenB;) {
            if (lenB - i <= lenA) {
                if (B.substr(i, lenB - i) != A.substr(0, lenB - i)) return -1;
                if (lenB - i <= lenA - reverseStr) return ret + 1;
                else return ret + 2;
            }
            else if (B.substr(i, lenA) != A) return -1;

            ret++;
            i += lenA;
        }
        return ret;
    }
    int repeatedStringMatch(string A, string B) {
        int lenA = A.size(), lenB = B.size(), minLen, reverseStr = 0;
        minLen = min(lenA, lenB);

        for (int i = 0; i < minLen; i++) {
            if (B[0] == A[0] && B.substr(0, minLen) == A.substr(0, minLen)) {
                if (lenA >= lenB) {
                    if (reverseStr) return 2;
                    else return 1;
                }
                return check(A, B, lenA, lenB, reverseStr);
            }
            else {
                int tmp = A[0];
                A.erase(A.begin());
                A.insert(A.end(), tmp);
                reverseStr++;
            }
        }
        return -1;
    }
};
