#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
// 这里不太懂到底是怎么重写的。。
struct cmpByKey {
    bool operator()(const Interval& a, const Interval& b) const {
        if (a.start < b.start) return true;
        else if (a.start == b.start) return a.end < b.end;
        else return false;
    }
};
vector<int> findRightInterval(vector<Interval>& intervals) {
    map<Interval, int, cmpByKey> myMap;
    int n = intervals.size();
    vector<int> ret(n, -1);
    for (int i = 0; i < n; i++) {
        myMap[intervals[i]] = i;
    }
    for (auto i = myMap.begin(); i != myMap.end(); i++) {
        for (auto j = i; j != myMap.end(); j++) {
            if (j->first.start >= i->first.end) {
                ret[i->second] = j->second;
                break;
            }
        }
    }
    return ret;
}
int main() {
    vector<Interval> intervals = {
        {3,4},{2,3},{1,2}
    };
    findRightInterval(intervals);
    return 0;
}
