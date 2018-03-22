/*
    一开始想的是，先求出每个职工的free time。然后再对这些free time求交集（两个集合求交的思路，while循环，两个指针同时遍历）
    参考 discuss。把所有的区间合在一起考虑。
**/
#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <set>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct cmpByKey {
    bool operator()(const Interval& a, const Interval& b) const {
        if (a.start < b.start) return true;
        else if (a.start == b.start) return a.end < b.end;
        else return false;
    }
};

void merge(vector<Interval>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].start <= vec[i - 1].end) {

            vec[i].start = min(vec[i].start, vec[i - 1].start);
            vec[i].end = max(vec[i].end, vec[i - 1].end);

            vec.erase(vec.begin() + i - 1);

            i--;
        }
    }
}
void getFree(vector<Interval>& ret, vector<Interval>& tmp) {
    // for (int i = 0; i < ret.size(); i++) {
    //     bool overlap = false;
    //     for (int j = 0; j < tmp.size(); j++) {
    //         if (tmp[j].start >= ret[i].end || tmp[j].end <= ret[i].start) continue;
    //         else {
    //             overlap = true;
    //             ret[i].start = max(ret[i].start, tmp[j].start);
    //             ret[i].end = min(ret[i].end, tmp[j].end);
    //         }
    //     }
    //     if (!overlap) {
    //         ret.erase(ret.begin() + i);
    //         i--;
    //     }
    // }

}
vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
    for (int i = 0; i < avails.size(); i++) {
        sort(avails[i].begin(), avails[i].end(), cmpByKey());
        merge(avails[i]);
    }

    vector<Interval> ret;
    if (avails.empty()) return ret;

    // 初始化common
    if (avails[0][0].start > 1) ret.push_back(Interval(1, avails[0][0].start));
    for (int i = 1; i < avails[0].size(); i++) {
        ret.push_back(Interval(avails[0][i - 1].end, avails[0][i].start));
    }

    for (int i = 1; i < avails.size(); i++) {
        vector<Interval> tmp;
        if (avails[i][0].start > 1) tmp.push_back(Interval(1, avails[i][0].start));

        for (int j = 1; j < avails[i].size(); j++) {
            ret.push_back(Interval(avails[i][j - 1].end, avails[i][j].start));
        }

        getFree(ret, tmp);
    }

    return ret;
}

int main() {

    vector<vector<Interval>> avails;

    vector<Interval> tmp;

    tmp.push_back(Interval(1,2));
    tmp.push_back(Interval(5,6));
    tmp.push_back(Interval(1,3));
    tmp.push_back(Interval(4,10));

    avails.push_back(tmp);
    employeeFreeTime(avails);

    return 0;
}

// 参考discuss的解法

#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class cmp {
public:
    bool operator() (const Interval& a, const Interval&b) const {
        return a.start > b.start;
    }
};

vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
    priority_queue<Interval, vector<Interval>, cmp> pq;
    vector<Interval> ret;

    for (int i = 0; i < schedule.size(); i++) {
        for (int j = 0; j < schedule[i].size(); j++) {
            pq.push(schedule[i][j]);
        }
    }

    Interval tmp = pq.top();
    pq.pop();
    // 这个地方是不是有问题，按照题意  Interval(1, tmp.start) 应该是第一个空闲区间？
    if (tmp.start > 1) ret.push_back(Interval(1, tmp.start));

    while (!pq.empty()) {
        Interval top = pq.top();

        pq.pop();

        if (top.start > tmp.end) ret.push_back(Interval(tmp.end, top.start));

        tmp.end = max(tmp.end, top.end);
    }

    return ret;
}

int main() {

    vector<vector<Interval>> avails;

    vector<Interval> tmp;

    tmp.push_back(Interval(1,2));
    tmp.push_back(Interval(5,6));
    tmp.push_back(Interval(1,3));
    tmp.push_back(Interval(4,10));

    avails.push_back(tmp);

    vector<Interval> tmp1;

    tmp1.push_back(Interval(1,2));
    tmp1.push_back(Interval(5,6));
    tmp1.push_back(Interval(1,3));
    tmp1.push_back(Interval(4,10));

   // avails.push_back(tmp1);

    employeeFreeTime(avails);

    return 0;
}
