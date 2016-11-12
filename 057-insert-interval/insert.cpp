/*
    此题在56题的基础之上直接插入一个新的元素就可。
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool comp(const Interval& a, const Interval&b) {
    return a.start<b.start;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), comp);
    ret.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i].start <= ret.back().end){
            Interval tmp(ret.back().start, max(ret.back().end, intervals[i].end));
            ret.pop_back();
            ret.push_back(tmp);
        } else{
            ret.push_back(intervals[i]);
        }
    }
    
    return ret;
}

int main(){
    vector<Interval> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    Interval tmp(4,9);
    cout << insert(intervals, tmp).size();
    return 0;
}
