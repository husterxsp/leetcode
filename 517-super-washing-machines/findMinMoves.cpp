class Solution {
public:
    /**
        注意理解题意，可以同时将多个机器里的衣服移动到临近的机器里。。
    
    */
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0), n = machines.size(), ret = 0, mean = 0;
        if (sum % n != 0) return -1;
        mean = sum / n;
        for (int i = 0; i < n; i++) {
            if (machines[i] > mean) ret += machines[i] - mean;
        }
        return ret;
    }
};
