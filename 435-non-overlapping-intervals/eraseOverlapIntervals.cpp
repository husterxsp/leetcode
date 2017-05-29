#include <iostream>
#include <vector>

using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
static bool compare(Interval& i, Interval& j) {
    if (i.start < j.start) return true;
    else if (i.start == j.start) return i.end < j.end;
    else return false;
}
/**
    一开始的思路是用一个数组保存每一个区间与其他区间的重合的个数,
    然后重合个数大的先删除，但是最后不怎么好处理。。。
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int n = intervals.size();
        vector<int> overlap(n, 0);
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n) {
                if (intervals[i].end > intervals[j].start) overlap[i]++;
                else break;
                j++;
            }
            j = i - 1;
            while (j >= 0) {
                if (intervals[i].start < intervals[j].end) overlap[i]++;
                else break;
                j--;
            }
        }
    }
*/
int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);

    int n = intervals.size(), last = 0, ret = 0;
    for (int i = 1; i < n; i++) {
        if (intervals[last].end > intervals[i].start) {
            ret++;
            if (intervals[last].end > intervals[i].end) last = i;
        }
        else {
            last = i;
        }
    }
    return ret;
}
int main() {
    vector<Interval> intervals = {
        {1,2}, {1,3}, {2,3}, {3,4}
    };
    cout << eraseOverlapIntervals(intervals) << endl;
}
