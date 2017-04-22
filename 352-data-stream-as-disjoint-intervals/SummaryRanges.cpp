#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
/**
    判断区间重叠与否，重叠的合并
*/
class SummaryRanges {
public:
    vector<Interval> list;
    /*Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        Interval cur(val, val);
        vector<Interval> vec;

        int pos = 0;
        for (int i = 0; i < list.size(); i++) {
            if (cur.start > list[i].end + 1) {
                vec.push_back(list[i]);
                pos++;
            }
            else if (cur.end + 1 < list[i].start) {
                vec.push_back(list[i]);
            }
            else {
                cur.start = min(cur.start, list[i].start);
                cur.end = max(cur.end, list[i].end);
            }
        }
        vec.insert(vec.begin() + pos, cur);
        list = vec;
    }

    vector<Interval> getIntervals() {
        return list;
    }
};

int main() {
    SummaryRanges obj = *new SummaryRanges();
    obj.addNum(1);
    obj.addNum(3);
    obj.addNum(7);
    obj.addNum(2);
    obj.addNum(6);
    vector<Interval> param_2 = obj.getIntervals();
    return 0;
}
