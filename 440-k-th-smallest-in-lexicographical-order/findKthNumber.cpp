/*
    参考：https://www.cnblogs.com/grandyang/p/6031787.html
    十叉树Denary Tree？
    待再看
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0) {
            long step = 0, first = cur, last = cur + 1;
            while (first <= n) {
                step += min(n - first + 1, last - first);

                first *= 10;
                last *= 10;
            }
            if (step <= k) {
                cur++;
                k -= step;
            }
            else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};
