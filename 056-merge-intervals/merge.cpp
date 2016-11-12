
/*
 解法一：尝试使用递归分治来解决，但是好像有点问题。。。。
 */

// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;

// struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };

// vector<Interval> getMerge(vector<Interval>& intervals, int left, int right){
//     int n = right-left+1;
//     vector<Interval> ret, tmp;
    
//     if(n == 0){
//         return intervals;
//     }
//     if(n == 1){
//         ret.push_back(intervals[left]);
//         return ret;
//     }
//     if(n == 2){
//         if(!(intervals[left].end > intervals[right].start || intervals[right].start > intervals[left].end))
//         {
//             int left_p = min(intervals[left].start, intervals[right].start);
//             int right_p = max(intervals[left].end, intervals[right].end);
//             ret.push_back({left_p, right_p});
//         } else {
//             ret.push_back({intervals[left].start, intervals[left].end});
//             ret.push_back({intervals[right].start, intervals[right].end});
//         }
//          return ret;
//     }
    
//     tmp = getMerge(intervals, left, (left+right)/2-1);
//     ret.insert(ret.end(), tmp.begin(), tmp.end());
//     tmp = getMerge(intervals, (left+right)/2, right);
//     ret.insert(ret.end(), tmp.begin(), tmp.end());

//     return getMerge(ret, 0, ret.size()-1);
// }

// vector<Interval> merge(vector<Interval>& intervals) {
//     return getMerge(intervals, 0, intervals.size()-1);
// }

// int main(){
//     vector<Interval> intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
//     cout << merge(intervals).size();
//     return 0;
// }
// 


/*
    解法二：先排序，再直接遍历，注意比较函数的写法直接重载操作符<,提交到leetcode有些问题。
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

// bool operator<(const Interval& a, const Interval&b) {
//     return a.start<b.start;
// }

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ret;
    
    if(!intervals.size()){
        return ret;
    }
    sort(intervals.begin(), intervals.end());
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
    vector<Interval> intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    cout << merge(intervals).size();
    return 0;
}
