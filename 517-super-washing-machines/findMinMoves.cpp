/*
    参考：
*/
class Solution {
public:
    /**
        注意理解题意，可以同时将多个机器里的衣服移动到临近的机器里。
    */
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0), n = machines.size();
        if (sum % n != 0) return -1;

        int ret = 0, mean = sum / n, cnt = 0;
        for (int m : machines) {
            cnt += m - mean;
            ret = max(ret, abs(cnt));

            if (m - mean > 0) ret = max(ret, m - mean);
        }

        return ret;
    }
};
