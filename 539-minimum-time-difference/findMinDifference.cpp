class Solution {
public:
    int convert2Int(string timeStr) {
        istringstream is(timeStr);
        int hour, minute;
        char c;
        is >> hour >> c >> minute;
        return hour * 60 + minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size(), ret = INT_MAX, pre = 0, cur = 0;
        if (!n) return 0;

        pre = convert2Int(timePoints[0]);
        for (int i = 1; i <= n; i++) {
            cur = convert2Int(timePoints[i % n]);
            int diff = cur - pre;
            if (i == n) diff += 1440;
            ret = min(ret, diff);
            pre = cur;
        }
        return ret;
    }
};
