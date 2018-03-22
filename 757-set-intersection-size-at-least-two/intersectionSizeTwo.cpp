// 参考discuss 贪心。为啥是对end排序？
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        int n = intervals.size(), ret = 0, p1 = -1, p2 = -1;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] <= p1) continue;
            if (intervals[i][0] > p2) {
                ret += 2;
                p1 = intervals[i][1] - 1;
                p2 = intervals[i][1];
            }
            else {
                ret++;
                p1 = p2;
                p2 = intervals[i][1];
            }
        }
        return ret;
    }
};
