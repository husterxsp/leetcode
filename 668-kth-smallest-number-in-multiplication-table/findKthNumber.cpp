/*
    参考 378. Kth Smallest Element in a Sorted Matrix
*/
class Solution {
public:
    int searchLessEqual(int m, int n, int mid) {
        int ret = 0, i = m, j = 1;
        while (i >= 1 && j <= n) {
            if (i * j <= mid) {
                ret += i;
                j++;
            }
            else {
                i--;
            }
        }
        return ret;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = searchLessEqual(m, n, mid);

            if (count >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
